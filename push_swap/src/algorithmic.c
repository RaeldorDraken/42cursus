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

int	ft_check_position_top(t_stks *lists, char stack)
{
	int	size;
	int	i;
	int	j;

	j = -1;
	if (stack == 'a')
	{
		if (lists->size_a / 2 < 20)
			size = lists->size_a;
		else
			size = 20;
		while (++j <= size)
		{
			i = -1;
			while (++i <= size)
			{
				if (lists->chunk[j - 1] == lists->a[i])
				{
					ft_putendl_fd(" entra", 1);
					i ++;
				}
				if (lists->chunk[j] > lists->a[i])
					lists->chunk[j] = lists->a[i];
			}
		}
	}
	return (size);
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
