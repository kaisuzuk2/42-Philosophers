/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:42:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/27 11:09:57 by kaisuzuk         ###   ########.fr       */
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
# define EXIT_FAILURE 1

# define CONF_SIZE 5

typedef struct s_atomic_bool
{
	pthread_mutex_t	lock;
	t_bool			is_flg;
}					t_atomic_bool;

typedef struct s_atomic_long
{
	pthread_mutex_t	lock;
	long long		value;
}					t_atomic_long;

typedef struct s_atomic_int
{
	pthread_mutex_t	lock;
	int				value;
}					t_atomic_int;

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
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
	t_atomic_bool	is_died;
	long long		start_time;
	t_philo_config	*conf;
}					t_table;

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	t_atomic_long	last_eat_time;
	t_atomic_int	eat_count;
	pthread_t		thread;
	t_table			*table;
}					t_philo;

typedef struct s_monitor
{
	pthread_mutex_t	*fork_lock;
	pthread_mutex_t	print_lock;
	t_atomic_bool	is_died;
	long long		start_time;
	t_philo_config	*conf;
	t_philo			*philos;
	pthread_t		thread;
}					t_monitor;

size_t				ft_strlen(const char *s);
t_bool				ft_is_digit(int ch);
long long			ft_atol(const char *nptr);

// xmalloc.c
void				*xmalloc(size_t size);

#endif
