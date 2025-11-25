/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:41:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/25 10:33:58 by kaisuzuk         ###   ########.fr       */
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

// print_state.c
void	print_state(t_philo *philo, const char *state);

// rthread_routine.c
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);

/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        get/set                         */
/*                                                                 */
/*-----------------------------------------------------------------*/

// set.c
void	set_start_time(long *start_time, long time);
void	set_died_flg(t_atomic_bool *is_dead);
void	set_eat_count(t_atomic_int *eat_count);
void	set_last_eat_time(t_atomic_long *last_eat_time, long time);

// get.c
long	get_ms_time(void);
t_bool	get_is_timeout_died(const long last_eat_time, const int time_to_died);
long	get_last_eat_time(t_atomic_long *last_eat_time);
t_bool	get_is_died(t_atomic_bool *is_died);

#endif