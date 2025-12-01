/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:36:13 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/30 15:42:20 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork_lock[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->r_fork]);
}

static t_bool	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	first_fork = &philo->table->fork_lock[philo->r_fork];
	second_fork = &philo->table->fork_lock[philo->l_fork];
	if (philo->id % 2)
	{
		first_fork = &philo->table->fork_lock[philo->l_fork];
		second_fork = &philo->table->fork_lock[philo->r_fork];
	}
	pthread_mutex_lock(first_fork);
	if (is_died(&philo->table->is_died))
	{
		pthread_mutex_unlock(first_fork);
		return (FALSE);
	}
	print_state(philo, ST_FORK);
	pthread_mutex_lock(second_fork);
	if (is_died(&philo->table->is_died))
	{
		release_forks(philo);
		return (FALSE);
	}
	print_state(philo, ST_FORK);
	return (TRUE);
}

static t_bool	do_eat(t_philo *philo, t_bool is_must_eat)
{
	if (is_died(&philo->table->is_died))
		return (FALSE);
	if (!take_forks(philo))
		return (FALSE);
	set_last_eat_time(&philo->last_eat_time, get_current_mstime());
	if (is_died(&philo->table->is_died))
	{
		release_forks(philo);
		return (FALSE);
	}
	print_state(philo, ST_EAT);
	sleep_until(philo->table->conf->time_to_eat);
	set_eat_count(&philo->eat_count);
	release_forks(philo);
	if (is_died(&philo->table->is_died))
		return (FALSE);
	if (is_must_eat)
		if (is_done_eating(&philo->eat_count, philo->table->conf->must_eat))
			return (FALSE);
	return (TRUE);
}

static t_bool	do_sleep(t_philo *philo, unsigned int rest_time)
{
	if (is_died(&philo->table->is_died))
		return (FALSE);
	print_state(philo, ST_SLEEP);
	sleep_until(rest_time);
	return (TRUE);
}

static t_bool do_think(t_philo *philo)
{
	if (is_died(&philo->table->is_died))
		return (FALSE);
	while (!is_can_eat(philo))
	{
		usleep(DF_SLEEP);
		if (is_died(&philo->table->is_died))
			return (FALSE);
	}
	return (TRUE);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_bool	is_must_eat;

	philo = (t_philo *)arg;
	is_must_eat = philo->table->conf->must_eat != NOT_SET;
	if (is_single_philo(philo))
		return (NULL);
	while (1)
	{
		if (!do_eat(philo, is_must_eat))
			return (NULL);
		if (!do_sleep(philo, philo->table->conf->time_to_sleep))
			return (NULL);
		if (!do_think(philo))
			return (NULL);
	}
	return (NULL);
}
