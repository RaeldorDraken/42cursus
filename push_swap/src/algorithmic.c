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
	
	size = -1;
	i = 0;
	if (stack == 'a')
	{
		lists->chunk[i] = lists->a[0];
		while (++size < lists->size_a / 2)
		{
			write(1, "entro\n", 6);
		
			ft_putnbr_fd(lists->chunk[i], 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(lists->a[size], 1);
			ft_putchar_fd('\n', 1);
			if (lists->chunk[i] > lists->a[size])
			{

				write(1, "incremento\n", 12);
				lists->chunk[i] = lists->a[size];
				i ++;
			}
			if (lists->size_a / 2 < 20)
			{
				write(1, "salida\n", 7);
				if (i == lists->size_a / 2)
					return (i);
			}
			else if (i > 20)
				return (i - 1);
		}
	}
	return (-1);
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
