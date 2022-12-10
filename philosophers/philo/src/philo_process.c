/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2022/12/10 20:51:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/philolib.h"

void	*phil_proc(void *void_philosopher)
{
	int		i;
	t_philo	*philo;
	t_args	*args;

	i = 0;
	philo = (t_philo *)void_philosopher;
	args = philo->args;
	if (philo->phil_id % 2)
		usleep(15000);
	while (!args->deaths)
	{
		break ;
	}
	return (NULL);
}
