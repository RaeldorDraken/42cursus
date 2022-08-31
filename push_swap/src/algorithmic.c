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

int	ft_set_size(t_stks *lists, int *j)
{
	*j = -1;
	if (lists->size_a / 2 < 20)
		return (lists->size_a / 2);
	else
		return (20);
}

int	ft_check_position_top(t_stks *lists)
{
	int	size;
	int	i;
	int	j;
	int	k;

	size = ft_set_size(lists, &j);
	while (++j <= size)
	{
		i = -1;
		while (++i <= lists->size_a / 2)
		{
			k = 20;
			while (--k > 0)
			{
				if (lists->chunk[k] == lists->a[i])
				{
					k = 20;
					i ++;
				}
			}
			if (lists->chunk[j] > lists->a[i])
				lists->chunk[j] = lists->a[i];
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
	i = ft_check_position_top(lists);
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
