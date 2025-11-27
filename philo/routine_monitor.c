/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/27 10:15:40 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
philo_routine
1) is_died flg check
2) get fork
3) eat
4) sleep
5) thinking

monitor_routine

*/

void	*monitor_routine(void *arg)
{
	t_monitor *mon;
	int i;

	mon = (t_monitor *)arg;
	while (1)
	{
		i = 0;
		while (i < mon->conf->n_philo)
		{
			if (is_timeout_died(get_last_eat_time(&mon->philos[i].last_eat_time),
					mon->conf->time_to_die))
			{
				set_died_flg(&mon->is_died);
				print_state(&mon->philos[i], ST_DIED);
				return (NULL);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}