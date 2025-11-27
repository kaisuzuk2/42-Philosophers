/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:09:52 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/27 14:11:24 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_zero(const long long n)
{
	return (n == 0);
}

static t_bool	is_overflow(const long long n)
{
	return (n > INT_MAX || n < INT_MIN);
}

static t_bool	is_negative(const long long n)
{
	return (n < 0);
}

static t_bool	parse_check(const long long *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (is_zero(arr[i]))
			return (FALSE);
		if (is_negative(arr[i]))
			return (FALSE);
		if (is_overflow(arr[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	parse(char **argv, t_philo_config *p_conf)
{
	size_t i;
	long long int arr[CONF_SIZE];
	int *p;

	memset(arr, 0, sizeof(arr));
	i = 0;
	argv++;
	while (argv[i])
	{
		arr[i] = ft_atol(argv[i]);
		i++;
	}
	if (!parse_check(arr, i))
		return (print_error("Error", "arguments must be positive integers"),
			FALSE);
	p = (int *)p_conf;
	i = 0;
	while (i < CONF_SIZE)
	{
		p[i] = (int)arr[i];
		i++;
	}
	return (TRUE);
}