/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 02:11:05 by root              #+#    #+#             */
/*   Updated: 2025/12/02 13:30:45 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_zero(const long long n)
{
	return (n == 0);
}

t_bool	is_overflow(const long long n)
{
	return (n > INT_MAX || n < INT_MIN);
}

t_bool	is_negative(const long long n)
{
	return (n < 0);
}
