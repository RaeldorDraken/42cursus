/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/03 16:14:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	error_terminate(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

int	*ft_convert_input(int ac, char **av)
{
	int	i;
	int	*list;

	i = -1;
	list = ft_calloc(sizeof(int), ac - 1);	
	while (++i < (ac - 1))
	{
		list[i]	= ft_atoi(av[i + 1]);
	}
	return(list);
}

void	ft_ra(t_stks *lists, int ac)
{
	int	temp;
	int	i;
	
	i = -1;
	temp = lists->a[0];
	while (++i < ac - 2)
		lists->a[i] = lists->a[i + 1];
	lists->a[i] = temp;
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stks *lists, int ac)
{
	int	temp;
	int	i;
	
	i = -1;
	temp = lists->b[0];
	while (++i < ac - 2)
		lists->b[i] = lists->b[i + 1];
	lists->b[i] = temp;
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stks *lists, int ac)
{
	int	temp;
	int	i;
	
	i = -1;
	temp = lists->a[0];
	while (++i < ac - 2)
		lists->a[i] = lists->a[i + 1];
	lists->a[i] = temp;
	i = -1;
	temp = lists->b[0];
	while (++i < ac - 2)
		lists->b[i] = lists->b[i + 1];
	lists->b[i] = temp;
	ft_putendl_fd("rr", 1);
}
void	ft_sa(t_stks *lists)
{
	int temp;

	temp = lists->a[1];
	lists->a[1] = lists->a[0];
	lists->a[0] = temp;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stks *lists)
{
	int temp;

	temp = lists->b[1];
	lists->b[1] = lists->b[0];
	lists->b[0] = temp;
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stks *lists)
{
	int temp;

	temp = lists->a[1];
	lists->a[1] = lists->a[0];
	lists->a[0] = temp;
	temp = lists->b[1];
	lists->b[1] = lists->b[0];
	lists->b[0] = temp;
	ft_putendl_fd("ss", 1);
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
	t_stks	lists;
	int		i;

	if (ac == 1)
		exit(0);
	i = -1;
	ft_check_input(ac, av);
	lists.b = ft_calloc(sizeof(int), ac);	
	lists.a = ft_convert_input(ac, av);
	while (++i < ac - 1)
	{
		ft_putnbr_fd(lists.a[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	i = -1;
	ft_ra(&lists, ac);
	while (++i < ac - 1)
	{
		ft_putnbr_fd(lists.a[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(lists.b[0], 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
