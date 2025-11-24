/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:39:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 14:30:15 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_last_eat_time(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->m_last_eat_time);
	philo->last_eat_time = time;
	pthread_mutex_unlock(&philo->m_last_eat_time);
}

void	set_eat_count(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_eat_count);
	philo->eat_count++;
	pthread_mutex_unlock(&philo->m_eat_count);
}

void	set_died_flg(t_monitor *mon)
{
	pthread_mutex_lock(&mon->m_is_died);
	mon->is_died = TRUE;
	pthread_mutex_unlock(&mon->m_is_died);
}

void	set_start_time(t_monitor *mon, long time)
{
	mon->start_time = time;
}
