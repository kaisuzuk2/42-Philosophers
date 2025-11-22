/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:42:07 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/22 10:50:25 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
# define GENERAL_H

# include <unistd.h>

typedef int	t_bool;
# define TRUE 1
# define FALSE 0

size_t		ft_strlen(const char *s);
t_bool		ft_is_digit(int ch);

#endif
