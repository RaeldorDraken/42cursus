/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/02 17:04:48 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	error_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int		*ft_convert_input(int ac, char **av)
{
	int	*list;

	list = ft_calloc(sizeof(int*), ac);
	while (--ac > 0)
		list[ac - 1] = ft_atoi(av[ac]);
	return (list);
}

void	ft_check_input(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i] != NULL && j < ft_strlen(av[i]))
		{
			if (ft_isdigit(av[i][j]) == 0 && av[i][j] != '-' && av[i][j] != '+')
				error_terminate();
			j++;
		}
		if (ft_latoi(av[i]) > (long int)INT_MAX
			|| ft_latoi(av[i]) < (long int)INT_MIN)
			error_terminate();
		j = 0;
		while (av[++j] != NULL)
		{
			if (!ft_strncmp(av[i], av[j], 11) && i != (int)j)
				error_terminate();
		}
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	*list;

	i = 0;
	if (ac == 1)
		exit(0);
	ft_check_input(ac, av);
	list = ft_convert_input(ac, av);
	while (i < ac)
	{
		ft_putnbr_fd(list[i++], 1);
		ft_putchar_fd('\t', 1);
	}
	ft_putchar_fd('\n', 1);
	return (0);
}
