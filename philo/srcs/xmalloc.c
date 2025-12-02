/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:55:16 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/12/02 13:32:56 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*xmalloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		print_error(SYSERR, "malloc failed.");
	return (res);
}
