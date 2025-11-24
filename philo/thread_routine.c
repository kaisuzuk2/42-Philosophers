/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 10:44:53 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
philo_routine
1) is_dead flg check
2) get fork
3) eat
4) sleep
5) thinking

monitor_routine

*/

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	set_last_eat_time(philo, philo->table->start_time);
	pthread_mutex_lock(&philo->table->m_print);
	printf("%d is start\n", philo->id);
	pthread_mutex_unlock(&philo->table->m_print);
	return (NULL);
}

void	*monitor_routine(void *arg)
{
	t_monitor *mon;

	mon = (t_monitor *)arg;
	pthread_mutex_lock(&mon->m_print);
	printf("monitor is start\n");
	pthread_mutex_unlock(&mon->m_print);
	return (NULL);
}