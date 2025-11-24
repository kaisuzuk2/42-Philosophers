/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:46:48 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 08:59:55 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_philo *philos, t_table *table, const int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		philos->id = i;
		philos->l_fork = i;
		philos->r_fork = (i + 1) % philo_num;
		philos->eat_count = 0;
		philos->table = table;
		pthread_mutex_init(&philos->m_last_eat_time, NULL);
		pthread_mutex_init(&philos->m_eat_count, NULL);
		philos++;
		i++;
	}
}

static void	init_monitor_mutex(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_mutex_init(&mon->m_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&mon->m_print, NULL);
	pthread_mutex_init(&mon->m_is_dead, NULL);
}

static t_bool	init_monitor(t_monitor *mon, t_philo *philos,
		t_philo_config *conf)
{
	pthread_mutex_t	*fork_arr;

	fork_arr = (pthread_mutex_t *)xmalloc(sizeof(pthread_mutex_t)
			* conf->n_philo);
	if (!fork_arr)
		return (FALSE);
	mon->m_fork = fork_arr;
	mon->conf = conf;
	mon->philos = philos;
	mon->is_dead = FALSE;
	init_monitor_mutex(mon);
	return (TRUE);
}

t_bool	init(t_monitor *mon, t_philo_config *conf)
{
	t_philo *philos;

	philos = (t_philo *)xmalloc(sizeof(t_philo) * conf->n_philo);
	if (!philos)
		return (FALSE);
	if (init_monitor(&mon, philos, &conf))
		return (free(philos), FALSE);
	init_philos(philos, (t_table *)&mon, conf->n_philo);
	return (TRUE);
}