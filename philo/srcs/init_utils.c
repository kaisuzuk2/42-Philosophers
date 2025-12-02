/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 04:41:33 by root              #+#    #+#             */
/*   Updated: 2025/12/02 13:30:01 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_atomic_bool(t_atomic_bool *b, const t_bool val)
{
	b->is_flg = val;
	pthread_mutex_init(&b->lock, NULL);
}

void	init_atomic_int(t_atomic_int *i, const int val)
{
	i->value = val;
	pthread_mutex_init(&i->lock, NULL);
}

void	init_atomic_long(t_atomic_long *l, const long long int val)
{
	l->value = val;
	pthread_mutex_init(&l->lock, NULL);
}
