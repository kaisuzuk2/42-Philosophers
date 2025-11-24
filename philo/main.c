/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:19:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 12:30:12 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) valid
2) thread create
3) thread join
*/
#include "philo.h"

void	create_thread(t_monitor *mon, t_bool is_monitor)
{
	int	i;

	if (is_monitor)
	{
		pthread_create(&mon->thread, NULL, monitor_routine, mon);
		return ;
	}
	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_create(&mon->philos[i].thread, NULL, philo_routine,
			&mon->philos[i]);
		i++;
	}
}

void	join_thread(t_monitor *mon, t_bool is_monitor)
{
	int	i;

	if (is_monitor)
	{
		pthread_join(mon->thread, NULL);
		return ;
	}
	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_join(mon->philos[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_philo_config	conf;
	t_monitor		mon;
	int				i;

	if (!valid(argc, argv))
		return (EXIT_FAILUE);
	if (!parse(argv, &conf))
		return (EXIT_FAILUE);
	if (!init(&mon, &conf))
		return (EXIT_FAILUE);
	create_thread(&mon, MONITOR);
	create_thread(&mon, PHILO);
	join_thread(&mon, MONITOR);
	join_thread(&mon, PHILO);
	
	i = 0;
	while (i < conf.n_philo)
	{
		pthread_mutex_destroy(&mon.m_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&mon.m_is_dead);
	pthread_mutex_destroy(&mon.m_print);
	i = 0;
	while (i < conf.n_philo)
	{
		pthread_mutex_destroy(&mon.philos[i].m_eat_count);
		pthread_mutex_destroy(&mon.philos[i].m_last_eat_time);
		i++;
	}
	free(mon.philos);
	free(mon.m_fork);
	return (EXIT_SUCCESS);
}
