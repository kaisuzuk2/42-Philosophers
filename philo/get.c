/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:30:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 10:17:05 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ms_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000));
}

t_bool	get_is_died(t_philo *philo)
{
	t_bool	res;

	pthread_mutex_lock(&philo->table->is_died.lock);
	res = philo->table->is_died.is_flg;
	pthread_mutex_unlock(&philo->table->is_died.lock);
	return (res);
}

t_bool	get_is_timeout_died(const long last_eat_time, const int time_to_died)
{
	return (get_ms_time() - last_eat_time > time_to_died);
}

long	get_last_eat_time(t_philo *philo)
{
	long	res;

	pthread_mutex_lock(&philo->last_eat_time.lock);
	res = philo->last_eat_time;
	pthread_mutex_unlock(&philo->last_eat_time.lock);
	return (res);
}
