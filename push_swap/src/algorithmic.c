/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:22:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/25 13:10:44 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

int		ft_check_position_top(t_stks *lists, char stack)
{
	int size;
	int	i;
	int	j;

	if (stack == 'a')
	{
		i = -1;
		while (++i < 21)
		{
			size = -1;
			while (++size < lists->size_a / 2)
			{
				j = i + 1;
				while (--j >= 0)
				{
					ft_putnbr_fd(j, 1);
					ft_putchar_fd(' ', 1);
					ft_putnbr_fd(size, 1);
					ft_putchar_fd(' ', 1);
					ft_putnbr_fd(i, 1);
					ft_putendl_fd("Entra", 1);
					ft_putnbr_fd(lists->chunk[j], 1);
					ft_putchar_fd(' ', 1);
					ft_putnbr_fd(lists->a[size], 1);
					ft_putchar_fd('\n', 1);
					if (lists->chunk[i] > lists->a[size] &&
						lists->chunk[j] != lists->a[size])
					{
						ft_putendl_fd("Intercambia", 1);
						lists->chunk[i] = lists->a[size];
					}
				}
			}
			if (lists->size_a / 2 < 20 && i == lists->size_a / 2)
				return (i - 1);
			ft_putendl_fd("sale", 1);
		}
	}
	return (i - 1);
}

void	ft_case_algorithmic(t_stks *lists)
{
	int	i;

	i = lists->size_a;
//	while (i > 0)
//	{
//		if ()
//	}
//	ft_basic_al(lists);
	i = ft_check_position_top(lists, 'a');
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (i > 0)
	{
		ft_putnbr_fd(lists->chunk[i], 1);
		ft_putchar_fd(' ', 1);
		i --;
	}
	ft_putchar_fd('\n', 1);
}

void	ft_basic_al(t_stks *lists)
{
	while (lists->size_a > 0)
	{
		while (ft_check_list_a(lists, 0) != 0)
			ft_ra(lists);
		ft_pb(lists);
	}
	while (lists->size_b > 0)
		ft_pa(lists);
}
