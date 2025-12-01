/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:55:16 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 10:56:35 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*xmalloc(size_t size)
{
	void *res;

	res = malloc(size);
	if (!res)
		return (print_error("SYSERROR", "malloc failed"), NULL);
	return (res);
}