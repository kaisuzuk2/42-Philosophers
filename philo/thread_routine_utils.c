/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:00:59 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/26 11:53:09 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%ld %d %s\n", get_time_stamp(philo->table->start_time), philo->id,
		state);
	pthread_mutex_unlock(&philo->table->print_lock);
}
