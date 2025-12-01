/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 09:07:20 by root              #+#    #+#             */
/*   Updated: 2025-12-01 09:07:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static long	get_last_time_idx(int idx, t_philo *philos)
{
	return (get_last_eat_time(&philos[idx].last_eat_time));
}


static void	quick_sort_order(int *eat_oder, t_philo *philos, int left,
		int right)
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

void	sort_oder(int *eat_oder, t_philo *philos, const int n_philo)
{
	if (n_philo <= 1)
		return ;
	quick_sort_order(eat_oder, philos, 0, n_philo - 1);
}