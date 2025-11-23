/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:41:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 10:56:46 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNS_H
# define EXTERNS_H

# include "general.h"

// valid.c 
t_bool	valid(int argc, char **argv);

// parse.c
t_bool	parse(char **argv, t_philo_config *p_conf);

#endif