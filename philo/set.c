/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:39:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 10:18:59 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_eat_time(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->last_eat_time.lock);
	philo->last_eat_time.value = time;
	pthread_mutex_unlock(&philo->last_eat_time.lock);
}

void	set_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_count.lock);
	philo->eat_count.value++;
	pthread_mutex_unlock(&philo->eat_count.lock);
}

void	set_died_flg(t_monitor *mon)
{
	pthread_mutex_lock(&mon->is_died.lock);
	mon->is_died.is_flg = TRUE;
	pthread_mutex_unlock(&mon->is_died.lock);
}

void	set_start_time(t_monitor *mon, long time)
{
	mon->start_time = time;
}
