/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor_scheduler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 09:10:24 by root              #+#    #+#             */
/*   Updated: 2025-12-01 09:10:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// quick_sort.c
void	sort_oder(int *eat_oder, t_philo *philos, const int n_philo);

static void	reset_can_eat(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		set_can_eat(&mon->philos[i].can_eat, FALSE);
		i++;
	}
}

static void	init_eat_oder(int *eat_oder, const int n_philo)
{
	int	i;

	i = 0;
	while (i < n_philo)
	{
		eat_oder[i] = i;
		i++;
	}
}

static void	fair_eat(int *eat_oder, t_philo *philos, const int n_philo)
{
	const int	max_eat = n_philo / 2;
	int			left;
	int			right;
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (i < n_philo && count < max_eat)
	{
		left = (eat_oder[i] - 1 + n_philo) % n_philo;
		right = (eat_oder[i] + 1) % n_philo;
		if (!is_can_eat(&philos[left]) && !is_can_eat(&philos[right]))
		{
			set_can_eat(&philos[eat_oder[i]].can_eat, TRUE);
			count++;
		}
		i++;
	}
}

void	update_fair_eat(t_monitor *mon)
{
	reset_can_eat(mon);
	init_eat_oder(mon->eat_oder, mon->conf->n_philo);
	sort_oder(mon->eat_oder, mon->philos, mon->conf->n_philo);
	fair_eat(mon->eat_oder, mon->philos, mon->conf->n_philo);
}