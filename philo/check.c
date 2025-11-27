/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:37:04 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/28 08:27:41 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_died(t_atomic_bool *is_died)
{
	t_bool	res;

	pthread_mutex_lock(&is_died->lock);
	res = is_died->is_flg;
	pthread_mutex_unlock(&is_died->lock);
	return (res);
}

t_bool	is_timeout_died(const long long last_eat_time, const int time_to_died)
{
	return (get_current_mstime() - last_eat_time > time_to_died);
}

t_bool	is_done_eating(t_atomic_int *eat_count, const int must_eat)
{
	t_bool	res;

	pthread_mutex_lock(&eat_count->lock);
	res = eat_count->value >= must_eat;
	pthread_mutex_unlock(&eat_count->lock);
	return (res);
}

t_bool	is_single_philo(t_philo *philo)
{
	return (philo->l_fork == philo->r_fork);
}