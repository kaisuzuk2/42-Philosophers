/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:37:23 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/12/02 13:28:34 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(const char *label, const char *msg)
{
	write(STDERR_FILENO, label, ft_strlen(label));
	write(STDERR_FILENO, &": ", 2);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, &"\n", 1);
}

void	print_usage(void)
{
	print_error("Usage",
		"./philo [n_philo] [time_to_die] [time_to_eat] [time_to_sleep] \
		+ (must_eat)");
}
