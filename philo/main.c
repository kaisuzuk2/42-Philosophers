/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:19:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/29 14:29:05 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) valid
2) thread create
3) thread join
*/
#include "philo.h"

int	create_thread(t_monitor *mon, t_bool is_monitor)
{
	int	i;
	int s;

	if (is_monitor)
		return (pthread_create(&mon->thread, NULL, monitor_routine, mon));
	i = 0;
	while (i < mon->conf->n_philo)
	{
		s = pthread_create(&mon->philos[i].thread, NULL, philo_routine,
			&mon->philos[i]);
		if (s)
		{
			while (--i >= 0)
				pthread_join(mon->philos[i].thread, NULL);
			break;
		}
		i++;
	}
	return (s);
}

int	join_thread(t_monitor *mon, t_bool is_monitor)
{
	int	i;
	int s;

	if (is_monitor)
		return (pthread_join(mon->thread, NULL));
	i = 0;
	s = 0;
	while (i < mon->conf->n_philo)
	{
		s = pthread_join(mon->philos[i].thread, NULL);
		i++;
	}
	return (s);
}

void	destroy_mutex(t_monitor *mon)
{
	int	i;

	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_mutex_destroy(&mon->fork_lock[i]);
		i++;
	}
	pthread_mutex_destroy(&mon->is_died.lock);
	pthread_mutex_destroy(&mon->print_lock);
	i = 0;
	while (i < mon->conf->n_philo)
	{
		pthread_mutex_destroy(&mon->philos[i].eat_count.lock);
		pthread_mutex_destroy(&mon->philos[i].last_eat_time.lock);
		i++;
	}
}

int	execute_thread(t_monitor *mon)
{
	if (create_thread(mon, PHILO) || create_thread(mon, MONITOR))
	{
		print_error("SYSERROR", "pthread_create failed.");
		return (EXIT_FATALERR);
	}
	if (join_thread(mon, PHILO) || join_thread(mon, MONITOR))
	{
		print_error("SYSERROR", "pthread_join failed.");
		return (EXIT_FATALERR);
	}
	destroy_mutex(mon);
	free(mon->philos);
	free(mon->fork_lock);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_philo_config	conf;
	t_monitor		mon;

	if (!valid(argc, argv))
		return (EXIT_FAILURE);
	if (!parse(argv, &conf))
		return (EXIT_FAILURE);
	if (!init(&mon, &conf))
		return (EXIT_FAILURE);
	set_start_time(&mon.start_time);
	return (execute_thread(&mon));
}
