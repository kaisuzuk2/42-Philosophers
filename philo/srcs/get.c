/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:30:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/12/02 13:29:21 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_current_mstime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec * 1000LL) + (long long)(tv.tv_usec / 1000LL));
}

long long	get_last_eat_time(t_atomic_long *last_eat_time)
{
	long long	res;

	pthread_mutex_lock(&last_eat_time->lock);
	res = last_eat_time->value;
	pthread_mutex_unlock(&last_eat_time->lock);
	return (res);
}

long long	get_time_stamp(const long long start_time)
{
	return (get_current_mstime() - start_time);
}

int	get_eat_count(t_atomic_int *eat_count)
{
	int	res;

	pthread_mutex_lock(&eat_count->lock);
	res = eat_count->value;
	pthread_mutex_unlock(&eat_count->lock);
	return (res);
}
