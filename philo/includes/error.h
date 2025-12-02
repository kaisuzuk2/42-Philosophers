/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:09:23 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/22 15:31:13 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define SYSERR "SYSERROR"
# define CREATE_ERR "pthread_create failed."

void	print_error(const char *label, const char *msg);
void	print_usage(void);

#endif