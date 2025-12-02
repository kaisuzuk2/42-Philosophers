/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 01:33:58 by root              #+#    #+#             */
/*   Updated: 2025/12/02 13:52:32 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_mutex_destroy(&mon->fork_lock[i]);
		pthread_mutex_destroy(&mon->philos[i].eat_count.lock);
		pthread_mutex_destroy(&mon->philos[i].last_eat_time.lock);
		i++;
	}
	pthread_mutex_destroy(&mon->is_died.lock);
	pthread_mutex_destroy(&mon->print_lock);
}

void	dispose(t_monitor *mon)
{
	destroy_mutex(mon);
	free(mon->fork_lock);
	free(mon->philos);
	free(mon->eat_oder);
}
