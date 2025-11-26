/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:22:57 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/26 11:40:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "dispose.h"
# include "error.h"
# include "externs.h"
# include "general.h"

# define MUST_EAT_ARG 5

# define MIN_ARG 5
# define MAX_ARG 6

# define MONITOR 1
# define PHILO 0

# define ST_FORK "has taken a fork"
# define ST_EAT "is eating"
# define ST_SLEEP "is sleeping"
# define ST_THINK "is thinking"
# define ST_DIED "died"
# define ST_FIN "is finished"

#endif