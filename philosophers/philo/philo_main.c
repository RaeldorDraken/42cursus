/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:55:57 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/14 11:17:05 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philolib.h"

//errno:
//	1 = wrong number of arguments
void end_program(int errno)
{
	if (errno == 1)
		write(2, "Error: Wrong number of arguments\n", 33);
	exit(errno);	
}

int	main(int ac, char **av)
{
	if (ac < 4 || ac > 5)
		end_program(1);
	printf("enters: %s\n", av[1]);
	return (0);
}
