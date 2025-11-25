/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:39:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 10:30:37 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_eat_time(t_atomic_long *last_eat_time, long time)
{
	pthread_mutex_lock(&last_eat_time->lock);
	last_eat_time->value = time;
	pthread_mutex_unlock(&last_eat_time->lock);
}

void	set_eat_count(t_atomic_int *eat_count)
{
	pthread_mutex_lock(&eat_count->lock);
	eat_count->value++;
	pthread_mutex_unlock(&eat_count->lock);
}

void	set_died_flg(t_atomic_bool *is_died)
{
	pthread_mutex_lock(&is_died->lock);
	is_died->is_flg = TRUE;
	pthread_mutex_unlock(&is_died->lock);
}

void	set_start_time(long *start_time, long time)
{
	*start_time = time;
}
