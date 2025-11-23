/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaisuzuk <kaisuzuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:19:20 by kaisuzuk          #+#    #+#             */
/*   Updated: 2025/11/23 12:47:02 by kaisuzuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1) valid
2) thread create
3) thread join
*/
#include "philo.h"


int	main(int argc, char *argv[])
{
	t_philo_config	conf;
	t_monitor		mon;

	if (!valid(argc, argv))
		return (EXIT_FAILUE);
	if (!parse(argv, &conf))
		return (EXIT_FAILUE);
	if (!init(&mon, &conf))
		return (EXIT_FAILUE);
		
	return (EXIT_SUCCESS);
}
