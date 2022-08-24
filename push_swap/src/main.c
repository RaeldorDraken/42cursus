/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/18 18:56:24 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	error_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

long int	*ft_convert_input(int ac, char **av)
{
	int			i;
	long int	*list;

	i = -1;
	list = ft_calloc(sizeof(long int), (ac - 1));
	while (++i < (ac - 1))
		list[i] = ft_latoi(av[i + 1]);
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

//this function must be eliminated when finished testing results
void	ft_test_check_result(t_stks *lists)
{
	int	i;

	i = -1;
	ft_putstr_fd("result: ", 1);
	while (++i < lists->size_a)
	{
		ft_putnbr_fd(lists->a[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	i = -1;
	while (++i < lists->size_b)
	{
		ft_putnbr_fd(lists->b[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("steps taken: ", 1);
	ft_putnbr_fd(lists->steps, 1);
	ft_putchar_fd('\n', 1);
}

int	main(int ac, char **av)
{
	t_stks	lists;

	if (ac == 1)
		exit(0);
	ft_check_input(ac, av);
	lists.b = ft_calloc(sizeof(long int), (ac - 1));
	lists.a = ft_convert_input(ac, av);
	lists.size_a = ac - 1;
	lists.size_b = 0;
	lists.steps = 0;
	ft_check_cases(&lists);
	ft_test_check_result(&lists);
	exit(0);
	return (0);
}
