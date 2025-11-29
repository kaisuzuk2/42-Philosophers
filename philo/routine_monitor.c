/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:35:27 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/29 15:20:29 by kaisuzuk         ###   ########.fr       */
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
				mon->conf->time_to_die, mon->start_time))
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

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// static void	sort_oder(int *eat_oder, t_philo *philos, const int n_philo)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < n_philo)
// 	{
// 		j = i;
// 		while (j < n_philo - 1)
// 		{
// 			if (get_last_eat_time(&philos[eat_oder[j]].last_eat_time) > get_last_eat_time(&philos[eat_oder[j
// 					+ 1]].last_eat_time))
// 				ft_swap(&eat_oder[j], &eat_oder[j + 1]);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static long	get_last_time_idx(int idx, t_philo *philos)
{
	return (get_last_eat_time(&philos[idx].last_eat_time));
}

static void	quick_sort_order(int *eat_oder, t_philo *philos, int left, int right)
{
	int		i;
	int		j;
	long	pivot;

	i = left;
	j = right;
	pivot = get_last_time_idx(eat_oder[(left + right) / 2], philos);
	while (i <= j)
	{
		while (get_last_time_idx(eat_oder[i], philos) < pivot)
			i++;
		while (get_last_time_idx(eat_oder[j], philos) > pivot)
			j--;
		if (i <= j)
		{
			ft_swap(&eat_oder[i], &eat_oder[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		quick_sort_order(eat_oder, philos, left, j);
	if (i < right)
		quick_sort_order(eat_oder, philos, i, right);
}

static void	sort_oder(int *eat_oder, t_philo *philos, const int n_philo)
{
	if (n_philo <= 1)
		return ;
	quick_sort_order(eat_oder, philos, 0, n_philo - 1);
}


static void	fair_eat(int *eat_oder, t_philo *philos, const int n_philo)
{
	const int	max_eat = n_philo / 2;
	int			i;
	int			check_oder;

	i = 0;
	check_oder = 0;
	while (i < n_philo)
	{
		if (eat_oder[i] == 0)
		{
			if (!is_can_eat(&philos[eat_oder[i] + 1])
				&& !is_can_eat(&philos[n_philo - 1]))
			{
				set_can_eat(&philos[eat_oder[i]].can_eat, TRUE);
				check_oder++;
			}
		}
		else if (eat_oder[i] == n_philo - 1)
		{
			if (!is_can_eat(&philos[0]) && !is_can_eat(&philos[eat_oder[i]
					- 1]))
			{
				set_can_eat(&philos[eat_oder[i]].can_eat, TRUE);
				check_oder++;
			}
		}
		else
		{
			if (!is_can_eat(&philos[eat_oder[i] + 1])
				&& !is_can_eat(&philos[eat_oder[i] - 1]))
			{
				set_can_eat(&philos[eat_oder[i]].can_eat, TRUE);
				check_oder++;
			}
		}
		i++;
		if (check_oder > max_eat)
			break ;
	}
}

static void	update_fari_eat(t_monitor *mon)
{
	reset_can_eat(mon);
	init_eat_oder(mon->eat_oder, mon->conf->n_philo);
	sort_oder(mon->eat_oder, mon->philos, mon->conf->n_philo);
	fair_eat(mon->eat_oder, mon->philos, mon->conf->n_philo);
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
		update_fari_eat(mon);
		usleep(MON_SLEEP);
	}
	return (NULL);
}