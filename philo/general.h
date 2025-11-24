/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:42:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/24 14:50:43 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef int			t_bool;
# define TRUE 1
# define FALSE 0

# define EXIT_SUCCESS 0
# define EXIT_FAILUE 1

# define CONF_SIZE 5

typedef struct s_philo_config
{
	int				n_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				must_eat;
}					t_philo_config;

typedef struct s_table
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_is_died;
	t_bool			is_died;
	long			start_time;
	t_philo_config	*conf;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	pthread_mutex_t	m_last_eat_time;
	long			last_eat_time;
	pthread_mutex_t	m_eat_count;
	int				eat_count;
	pthread_t		thread;
	t_table			*table;
}					t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	*m_fork;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_is_died;
	t_bool			is_died;
	long			start_time;
	t_philo_config	*conf;
	t_philo			*philos;
	pthread_t		thread;
}					t_monitor;

size_t				ft_strlen(const char *s);
t_bool				ft_is_digit(int ch);
long				ft_atol(const char *nptr);

// xmalloc.c
void				*xmalloc(size_t size);

#endif
