/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:30:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/26 11:41:24 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_mstime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((long)(tv.tv_sec * 1000) + (long)(tv.tv_usec / 1000));
}

long	get_last_eat_time(t_atomic_long *last_eat_time)
{
	long	res;

	pthread_mutex_lock(&last_eat_time->lock);
	res = last_eat_time->value;
	pthread_mutex_unlock(&last_eat_time->lock);
	return (res);
}

long	get_time_stamp(const start_time)
{
	return (get_current_mstime() - start_time);
}
