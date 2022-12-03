/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:09:17 by eros-gir          #+#    #+#             */
/*   Updated: 2022/12/03 12:19:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/philolib.h"

//action is the type of text to print:
//F = taken fork S = sleeping T = thinking D = died;
void	ft_print_phil(long int time, long int philnum, char action)
{
	if (action == 'F')
		printf("%ld %ld has taken a fork\n", time, philnum);
	else if (action == 'S')
		printf("%ld %ld is sleeping\n", time, philnum);
	else if (action == 'E')
		printf("%ld %ld is eating\n", time, philnum);
	else if (action == 'T')
		printf("%ld %ld is thinking\n", time, philnum);
	else if (action == 'D')
		printf("%ld %ld died\n", time, philnum);
}
