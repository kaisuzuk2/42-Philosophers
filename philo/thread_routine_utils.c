/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:00:59 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 11:18:50 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%d %s\n", philo->id, state);
	pthread_mutex_unlock(&philo->table->print_lock);
}

unsigned int	ms_to_micro(int ms_time)
{
	return ((unsigned int)ms_time * 1000);
}