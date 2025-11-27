/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/27 15:30:18 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	check_timeout_died(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		if (!is_done_eating(&mon->philos[i].eat_count, mon->conf->must_eat)
			&& is_timeout_died(get_last_eat_time(&mon->philos[i].last_eat_time),
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

static t_bool	check_must_eat(t_philo *philos, const int n_philo,
		const int must_eat)
{
	int	i;

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
		if (mon->conf->n_philo == 1)
		{
			print_state(&mon->philos[0], ST_DIED);
			return (NULL);
		}
		if (check_timeout_died(mon))
			return (NULL);
		if (check_must_eat(mon->philos, mon->conf->n_philo,
				mon->conf->must_eat))
			return (NULL);
		usleep(DF_SLEEP);
	}
	return (NULL);
}