/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:55:57 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/27 16:21:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/philolib.h"

//errno:
//	1 = wrong number of arguments; 2 = arguments on wrong forma;t
void	end_program(int errno)
{
	if (errno == 1)
		write(2, "Error: Wrong number of arguments\n", 33);
	else if (errno == 2)
		write(2, "Error: Arguments are invalid, only unsigned int accepted\n",
			57);
	exit(errno);
}

void	check_input(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while(av[i][++j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				end_program(2);
		}
	}

}

void convert_input(int ac, char **av, t_args *args)
{
	args->nbr_phil = ft_atol(av[1]);
	args->t_to_die = ft_atol(av[2]);
	args->t_to_slp = ft_atol(av[3]);
	if (ac == 5)
		args->nb_t_eat = ft_atol(av[4]);
	else
		args->nb_t_eat = -1;
}

void	philo_looping(t_args *args)
{
	printf("arguments: %ld %ld %ld %ld\n", args->nbr_phil, args->t_to_die,
		args->t_to_slp, args->nb_t_eat);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (ac < 4 || ac > 5)
		end_program(1);
	check_input(ac, av);
	convert_input(ac, av, &args);
	philo_looping(&args);
	return (0);
}
