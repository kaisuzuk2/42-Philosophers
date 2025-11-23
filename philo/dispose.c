/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:21:26 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 12:23:25 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dispose_philo(t_philo *philos, int philo_num)
{
	int i;

	i = 0;
	while (i < philo_num)
	{
		free(philos[i]);
		i++;
	}
}