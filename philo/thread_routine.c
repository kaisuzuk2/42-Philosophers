/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/26 10:07:53 by kaisuzuk         ###   ########.fr       */
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

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_bool	is_must_eat;

	philo = (t_philo *)arg;
	is_must_eat = philo->table->conf->must_eat != -1;
	set_last_eat_time(&philo->last_eat_time, philo->table->start_time);
	while (1)
	{
		if (get_is_died(&philo->table->is_died))
			return (NULL);
		pthread_mutex_lock(&philo->table->fork_lock[philo->l_fork]);
		pthread_mutex_lock(&philo->table->fork_lock[philo->r_fork]);
		print_state(philo, ST_FORK);
		set_last_eat_time(&philo->last_eat_time, get_ms_time());
		set_eat_count(&philo->eat_count);
		print_state(philo, ST_EAT);
		usleep(philo->table->conf->time_to_eat);
		pthread_mutex_unlock(&philo->table->fork_lock[philo->l_fork]);
		pthread_mutex_unlock(&philo->table->fork_lock[philo->r_fork]);
		if (get_is_died(&philo->table->is_died))
			return (NULL);
		print_state(philo, ST_SLEEP);
		usleep(philo->table->conf->time_to_sleep);
		if (get_is_died(&philo->table->is_died))
			return (NULL);
		print_state(philo, ST_THINK);
		usleep(philo->table->conf->time_to_think);
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
			if (get_is_timeout_died(get_last_eat_time(&mon->philos[i].last_eat_time),
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