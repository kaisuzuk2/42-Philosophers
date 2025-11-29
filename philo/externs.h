/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   externs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:41:32 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/29 10:24:49 by kaisuzuk         ###   ########.fr       */
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
t_bool		valid(int argc, char **argv);

// parse.c
t_bool		parse(char **argv, t_philo_config *p_conf);

// init.c
t_bool		init(t_monitor *mon, t_philo_config *conf);

/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        thread                         */
/*                                                                 */
/*-----------------------------------------------------------------*/

// rthread_routine.c
void		*philo_routine(void *arg);
void		*monitor_routine(void *arg);

// thread_routine_utils.c
void		print_state(t_philo *philo, const char *state);
void		sleep_until(const int end_time_ms);

/*-----------------------------------------------------------------*/
/*                                                                 */
/*                        get/set/check                       */
/*                                                                 */
/*-----------------------------------------------------------------*/

// set.c
void		set_start_time(long long *start_time);
void		set_died_flg(t_atomic_bool *is_dead);
void		set_eat_count(t_atomic_int *eat_count);
void		set_last_eat_time(t_atomic_long *last_eat_time, long long time);
void		set_can_eat(t_atomic_bool *can_eat, t_bool flg);

// get.c
long long	get_current_mstime(void);
long long	get_last_eat_time(t_atomic_long *last_eat_time);
long long	get_time_stamp(const long long start_time);
int			get_eat_count(t_atomic_int *eat_count);

// check.c
t_bool		is_died(t_atomic_bool *is_died);
t_bool		is_done_eating(t_atomic_int *eat_count, const int must_eat);
t_bool		is_timeout_died(const long long last_eat_time,
				const int time_to_died);
t_bool		is_single_philo(t_philo *philo);
t_bool		is_can_eat(t_philo *philo);

#endif