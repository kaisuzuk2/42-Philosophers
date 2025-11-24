/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:30:17 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 14:29:39 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_ms_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

t_bool get_is_died(t_philo *philo)
{
	t_bool res;

	pthread_mutex_lock(&philo->table->m_is_died);
	res = philo->table->is_died;
	pthread_mutex_unlock(&philo->table->m_is_died);
	return (res);
}



