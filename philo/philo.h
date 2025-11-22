/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 09:22:57 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/22 15:09:14 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "error.h"
# include "general.h"
# include "externs.h"

# define PHILO_ARG 1
# define DIE_ARG 2
# define EAT_ARG 3
# define SLEEP_ARG 4
# define MUST_EAT_ARG 5

# define MIN_ARG 5
# define MAX_ARG 6

typedef struct s_err_msg
{
	char	*label;
	char	*msg;
}			t_err_msg;

#endif