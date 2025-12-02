/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 08:52:15 by root              #+#    #+#             */
/*   Updated: 2025/12/02 13:32:13 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->table->fork_lock[philo->l_fork]);
	pthread_mutex_unlock(&philo->table->fork_lock[philo->r_fork]);
}

void	select_forks(t_philo *philo, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	*first = &philo->table->fork_lock[philo->r_fork];
	*second = &philo->table->fork_lock[philo->l_fork];
	if (philo->id % 2)
	{
		*first = &philo->table->fork_lock[philo->l_fork];
		*second = &philo->table->fork_lock[philo->r_fork];
	}
}

t_bool	lock_fork(t_philo *philo, pthread_mutex_t *fork)
{
	pthread_mutex_lock(fork);
	if (is_died(&philo->table->is_died))
	{
		pthread_mutex_unlock(fork);
		return (FALSE);
	}
	print_state(philo, ST_FORK);
	return (TRUE);
}

t_bool	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	select_forks(philo, &first_fork, &second_fork);
	if (!lock_fork(philo, first_fork))
		return (FALSE);
	if (!lock_fork(philo, second_fork))
	{
		pthread_mutex_unlock(first_fork);
		return (FALSE);
	}
	return (TRUE);
}
