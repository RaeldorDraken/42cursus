/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/05 18:18:30 by eros-gir         ###   ########.fr       */
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

void	ft_check_each_input(char *input)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(input))
	{
		if (ft_isdigit(input[i]) == 0 && input[i] != '-' && input[i] != '+')
			error_terminate();
		else if ((input[i] == '-' || input[i] == '+') && i != 0)
			error_terminate();
		i++;
	}
}

void	ft_check_input(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 0;
	while (++i < ac)
	{
		ft_check_each_input(av[i]);
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

void	ft_set_struct(t_stks *lists, int ac, char **av)
{
	int	i;

	i = -1;
	lists->b = ft_calloc(sizeof(long int), (ac - 1));
	lists->a = ft_convert_input(ac, av);
	lists->chunk = ft_calloc(sizeof(long int), 20);
	while (++i < 21)
		lists->chunk[i] = 9999999999;
	lists->size_a = ac - 1;
	lists->size_b = 0;
	lists->ga = ft_calloc(sizeof(int), (ac - 1));
	i = -1;
	while (++i < (ac - 1))
		lists->ga[i] = -1;
	lists->gb = ft_calloc(sizeof(int), (ac - 1));
	i = -1;
	while (++i < (ac - 1))
		lists->gb[i] = -1;
	lists->steps = 0;
	lists->hold_top = INT_MAX;
	lists->hold_bot = INT_MAX;
}

void	ft_check_result(t_stks *lists)
{
	int i = -1;
	while (++i < lists->size_a)
	{
		ft_putnbr_fd(lists->a[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
}

int	main(int ac, char **av)
{
	t_stks	lists;

	if (ac == 1)
		exit(0);
	ft_check_input(ac, av);
	ft_set_struct(&lists, ac, av);
	ft_set_game_list(&lists);
	ft_check_cases(&lists);
	exit(0);
	return (0);
}
