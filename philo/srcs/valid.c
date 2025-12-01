/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:52:48 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 10:53:17 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_str_number(char *str)
{
	while (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!ft_is_digit(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

static t_bool	valid_num(char **argv)
{
	argv++;
	while (*argv)
	{
		if (!is_str_number(*argv))
			return (FALSE);
		argv++;
	}
	return (TRUE);
}

t_bool	valid(int argc, char **argv)
{
	if (argc < MIN_ARG)
		return (print_error("Error", "too few arguments"), print_usage(),
			FALSE);
	if (argc > MAX_ARG)
		return (print_error("Error", "too many argumants"), print_usage(),
			FALSE);
	if (!valid_num(argv))
		return (print_error("Error", "arguments not a number"), FALSE);
	return (TRUE);
}