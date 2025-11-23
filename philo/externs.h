/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:41:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 14:45:38 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTERNS_H
# define EXTERNS_H

# include "general.h"

/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        init                         */
/*                                                                 */
/*-----------------------------------------------------------------*/

// valid.c
t_bool	valid(int argc, char **argv);

// parse.c
t_bool	parse(char **argv, t_philo_config *p_conf);

// init.c
t_bool	init(t_monitor *mon, t_philo_config *conf);

/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        thread                         */
/*                                                                 */
/*-----------------------------------------------------------------*/



/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        get/set                         */
/*                                                                 */
/*-----------------------------------------------------------------*/

// set.c
void	set_start_time(t_monitor *mon, long time);
void	set_dead_flg(t_monitor *mon);
void	set_eat_count(t_philo *philo);
void	set_last_eat_time(t_philo *philo, long time);

// get.c
long get_ms_time(void);



#endif