/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/08 11:38:06 by eros-gir         ###   ########.fr       */
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
