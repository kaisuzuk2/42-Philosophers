/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/26 11:57:51 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
philo_routine
1) is_died flg check
2) get fork
3) eat
4) sleep
5) thinking

monitor_routine

*/

static t_bool	do_eat(t_philo *philo, t_bool is_must_eat)
{
	if (is_died(&philo->table->is_died))
		return (FALSE);
	pthread_mutex_lock(&philo->table->fork_lock[philo->l_fork]);
	print_state(philo, ST_FORK);
	pthread_mutex_lock(&philo->table->fork_lock[philo->r_fork]);
	print_state(philo, ST_FORK);
	set_last_eat_time(&philo->last_eat_time, get_current_mstime());
	if (is_died(&philo->table->is_died))
	{
		pthread_mutex_unlock(&philo->table->fork_lock[philo->l_fork]);
		pthread_mutex_unlock(&philo->table->fork_lock[philo->r_fork]);
		return (FALSE);
	}
	print_state(philo, ST_EAT);
	usleep(philo->table->conf->time_to_eat);
	set_eat_count(&philo->eat_count);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->r_fork]);
	if (is_died(&philo->table->is_died))
		return (FALSE);
	if (is_must_eat)
		if (is_done_eating(&philo->eat_count, philo->table->conf->must_eat))
			return (FALSE);
	return (TRUE);
}

static t_bool	do_rest(t_philo *philo, unsigned int rest_time,
		const char *state)
{
	if (is_died(&philo->table->is_died))
		return (FALSE);
	print_state(philo, state);
	usleep(rest_time);
	return (TRUE);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_bool	is_must_eat;

	philo = (t_philo *)arg;
	is_must_eat = philo->table->conf->must_eat != -1;
	set_last_eat_time(&philo->last_eat_time, philo->table->start_time);
	while (1)
	{
		if (!do_eat(philo, is_must_eat))
			return (NULL);
		if (!do_rest(philo, philo->table->conf->time_to_sleep, ST_SLEEP))
			return (NULL);
		if (!do_rest(philo, philo->table->conf->time_to_think, ST_THINK))
			return (NULL);
	}
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_monitor *mon;
	int i;

	mon = (t_monitor *)arg;
	while (1)
	{
		i = 0;
		while (i < mon->conf->n_philo)
		{
			if (is_timeout_died(get_last_eat_time(&mon->philos[i].last_eat_time),
					mon->conf->time_to_die))
			{
				set_died_flg(&mon->is_died);
				print_state(&mon->philos[i], ST_DIED);
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}