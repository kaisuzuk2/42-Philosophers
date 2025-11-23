/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:42:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 09:36:42 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <limits.h>
# include <unistd.h>
# include <pthread.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

# define CONF_SIZE 5

typedef struct s_philo_config
{
	int		n_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		must_eat;
}			t_philo_config;

size_t		ft_strlen(const char *s);
t_bool		ft_is_digit(int ch);
long		ft_atol(const char *nptr);

#endif
