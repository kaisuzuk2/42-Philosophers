/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:22:57 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 10:51:26 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error.h"
# include "externs.h"
# include "general.h"

# define MUST_EAT_ARG 5

# define MIN_ARG 5
# define MAX_ARG 6

typedef struct s_table
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_is_dead;
	long			start_time;
	t_philo_config	*conf;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	long			last_eat_time;
	int				eat_count;
	pthread_t		thread;
	t_table			*table;
}					t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_is_dead;
	long			start_time;
	t_philo_config	*conf;
	t_philo			*philos;
}					t_monitor;

#endif