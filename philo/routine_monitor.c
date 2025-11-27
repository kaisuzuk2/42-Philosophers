/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/27 13:19:04 by kaisuzuk         ###   ########.fr       */
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

static t_bool	check_timeout_died(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		if (is_timeout_died(get_last_eat_time(&mon->philos[i].last_eat_time),
				mon->conf->time_to_die))
		{
			set_died_flg(&mon->is_died);
			print_state(&mon->philos[i], ST_DIED);
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

static t_bool check_must_eat(t_philo *philos, const int n_philo, const int must_eat)
{
	int i;

	i = 0;
	while (i < n_philo)
	{
		if (!is_done_eating(&philos[i].eat_count, must_eat))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	*monitor_routine(void *arg)
{
	t_monitor *mon;

	mon = (t_monitor *)arg;
	while (1)
	{
		if (check_timeout_died(mon))
			return (NULL);
		if (check_must_eat(mon->philos, mon->conf->n_philo, mon->conf->must_eat))
			return (NULL);
		usleep(DF_SLEEP);
	}
	return (NULL);
}