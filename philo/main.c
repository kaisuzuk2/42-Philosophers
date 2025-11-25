/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:19:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 10:34:39 by kaisuzuk         ###   ########.fr       */
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
	create_thread(mon, MONITOR);
	create_thread(mon, PHILO);
	join_thread(mon, MONITOR);
	join_thread(mon, PHILO);
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
		return (EXIT_FAILUE);
	if (!parse(argv, &conf))
		return (EXIT_FAILUE);
	if (!init(&mon, &conf))
		return (EXIT_FAILUE);
	return (execute_thread(&mon));
}
