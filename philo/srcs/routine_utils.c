/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 08:55:40 by root              #+#    #+#             */
/*   Updated: 2025-12-01 08:55:40 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, const char *state)
{
	pthread_mutex_lock(&philo->table->print_lock);
	if (is_died(&philo->table->is_died))
	{
		pthread_mutex_unlock(&philo->table->print_lock);
		return ;
	}
	printf("%lld %d %s\n", get_time_stamp(philo->table->start_time), philo->id,
		state);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	sleep_until(const int end_time_ms)
{
	long long	end;

	end = get_current_mstime() + end_time_ms;
	while (get_current_mstime() < end)
		usleep(DF_SLEEP);
}
