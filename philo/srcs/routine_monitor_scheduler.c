/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor_scheduler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 09:10:24 by root              #+#    #+#             */
/*   Updated: 2025/12/02 13:42:49 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// quick_sort.c
void		quick_sort(int *arr, int size, t_philo *philos);

static void	init_round(int *eat_oder, t_philo *philos, const int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		set_can_eat(&philos[i].can_eat, FALSE);
		eat_oder[i] = i;
		i++;
	}
}

static void	set_round(int *eat_oder, t_philo *philos, const int n_philo)
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
		if (!is_can_eat(&philos[left].can_eat) && !is_can_eat(&philos[right].can_eat))
		{
			set_can_eat(&philos[eat_oder[i]].can_eat, TRUE);
			count++;
		}
		i++;
	}
}

void	scheduler(t_monitor *mon)
{
	init_round(mon->eat_oder, mon->philos, mon->conf->n_philo);
	quick_sort(mon->eat_oder, mon->conf->n_philo, mon->philos);
	set_round(mon->eat_oder, mon->philos, mon->conf->n_philo);
}
