/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 12:46:48 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/29 11:12:58 by kaisuzuk         ###   ########.fr       */
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
		philos->eat_count.value = 0;
		philos->table = table;
		pthread_mutex_init(&philos->last_eat_time.lock, NULL);
		pthread_mutex_init(&philos->eat_count.lock, NULL);
		pthread_mutex_init(&philos->can_eat.is_flg, NULL);
		philos->can_eat.is_flg = TRUE;
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
		pthread_mutex_init(&mon->fork_lock[i], NULL);
		i++;
	}
	pthread_mutex_init(&mon->print_lock, NULL);
	pthread_mutex_init(&mon->is_died.lock, NULL);
}

static t_bool	init_monitor(t_monitor *mon, t_philo *philos,
		t_philo_config *conf)
{
	mon->fork_lock = (pthread_mutex_t *)xmalloc(sizeof(pthread_mutex_t)
			* conf->n_philo);
	if (!mon->fork_lock)
		return (FALSE);
	mon->eat_oder = (int *)xmalloc(sizeof(int) * conf->n_philo);
	if (!mon->eat_oder)
	{
		free(mon->fork_lock);
		return (FALSE);
	}
	mon->conf = conf;
	mon->philos = philos;
	mon->is_died.is_flg = FALSE;
	init_monitor_mutex(mon);
	return (TRUE);
}

t_bool	init(t_monitor *mon, t_philo_config *conf)
{
	t_philo *philos;

	philos = (t_philo *)xmalloc(sizeof(t_philo) * conf->n_philo);
	if (!philos)
		return (FALSE);
	if (!init_monitor(mon, philos, conf))
		return (free(philos), FALSE);
	init_philos(philos, (t_table *)mon, conf->n_philo);
	return (TRUE);
}