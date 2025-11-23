/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:39:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 14:23:41 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void set_last_eat_time(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->m_last_eat_time);
	philo->last_eat_time = time;
	pthread_mutex_unlock(&philo->m_last_eat_time);
}

void set_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->m_eat_count);
}

void set_dead_flg(t_monitor *mon)
{
	pthread_mutex_lock(&mon->m_is_dead);
	mon->is_dead = TRUE;
	pthread_mutex_unlock(&mon->m_is_dead);
}

