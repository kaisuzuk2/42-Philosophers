/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:19:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 10:50:55 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) valid
2) thread create
3) thread join
*/
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

static t_bool	valid_arg(int argc, char **argv)
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

int	main(int argc, char *argv[])
{
	t_philo_config conf;

	if (!valid_arg(argc, argv))
		return (1);
	if (!parse(argv, &conf))
		return (1);
	
	return (0);
}
