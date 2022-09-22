/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:22:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/09/20 11:52:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

int	ft_ra_nbr_moves(t_stks *lists)
{
	int	i;
	int	j;

	i = 0;
	while (i < lists->size_a)
	{
		j = -1;
		while (++j < 20)
		{
			if (lists->a[i] == lists->chunk[j])
				return (i);
		}
		i ++;
	}
	return (lists->size_a);
}

int	ft_rra_nbr_moves(t_stks *lists)
{
	int	i;
	int	j;

	i = lists->size_a - 1;
	while (i >= 0)
	{
		j = -1;
		while (++j < 20)
		{
			if (lists->a[i] == lists->chunk[j])
				return (-1 * (i - 1 - lists->size_a));
		}
		i --;
	}
	return (lists->size_a);
}
//do a sort b after pb, with checking if its the biggest numberand making sa
//and rb or rrb to move round the number to the right position.

//or i can check for the biggest or smallest of the chunk and push that number
//so can be pushed on top of the stack correctly that will be easier
void	ft_sort_b(t_stks *lists, int hold)
{
	int		bs;
	int		pos;
	long int temp;

	bs = lists->size_b;
	pos = 0;
	if (bs < 3)
		return ;
	while (bs > 0)
	{
		if (lists->b[bs] > hold)
			pos --;
		else if (lists->b[bs] < hold)
			pos ++;
		ft_putnbr_fd(lists->b[bs], 1);
		ft_putchar_fd('\n', 1);
		bs --;
	}
	bs = lists->size_b;
//
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(pos, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(lists->size_b, 1);
	ft_putchar_fd('|', 1);
//
	if (pos == lists->size_b - 2)
	{
		temp = -9999999999;
		while (bs > 0)
		{
			if (lists->chunk[bs] > temp)
				temp = lists->chunk[bs];
			bs --;
		}
		while (lists->chunk[bs] != temp)
		{
			ft_putnbr_fd(bs, 1);
			ft_putendl_fd(" entra", 1);
			ft_putnbr_fd(lists->size_b, 1);
			ft_putchar_fd('\n', 1);
			bs ++;
		}
		if (bs < lists->size_b / 2)
		{
			while (bs-- > 0)
				ft_rb(lists);
		}
		else
		{
			while (bs++ <= lists->size_b)
				ft_rrb(lists);
		}
	}
	else if (pos == -(lists->size_b - 2))
	{
		temp = 9999999999;
		while (bs > 0)
		{
			if (lists->chunk[bs] < temp)
				temp = lists->chunk[bs];
			bs --;
		}
		while (lists->chunk[bs] != temp)
			bs ++;
		if (bs < lists->size_b / 2)
		{
			while (bs-- > 0)
				ft_rb(lists);
		}
		else
		{
			while (pos++ <= lists->size_b)
				ft_rrb(lists);
		}
	}
	else
	{
		temp = hold;
		while (temp < 9999999999)
		{
			pos = lists->size_b - 1;
			while (pos >= 0)
			{
				if (lists->b[pos] == temp)
				{
					break ;
				}
				pos --;
			}
			if (lists->b[pos] == temp)
				break ;
			temp ++;
		}
		if (pos < lists->size_b / 2)
		{
			while (pos-- >= 0)
				ft_rb(lists);
		}
		else
		{
			while (pos++ < lists->size_b)
				ft_rrb(lists);
		}
	}
}

void	ft_pa_bottom(t_stks *lists)
{
	while (lists->a[0] != lists->hold_bot)
	{
		if (lists->b[0] > lists->hold_bot && lists->size_b > 1)
			ft_rrr(lists);
		else
			ft_rra(lists);
	}
	ft_sort_b(lists, lists->hold_bot);
	ft_pb(lists);
}

void	ft_pa_top(t_stks *lists)
{
	while (lists->a[0] != lists->hold_top)
	{
		if (lists->b[0] > lists->hold_top && lists->size_b > 1)
			ft_rr(lists);
		else
			ft_ra(lists);
	}
	ft_sort_b(lists, lists->hold_top);
	ft_pb(lists);
}

void	ft_case_algorithmic(t_stks *lists)
{
	int	i;
	int	size;

	i = -1;
	size = ft_check_chunk(lists);
	while (++i < size)
	{
		ft_set_hold_top(lists, size);
		ft_set_hold_bottom(lists, size);
		if (ft_ra_nbr_moves(lists) > ft_rra_nbr_moves(lists))
			ft_pa_bottom(lists);
		else
			ft_pa_top(lists);
	}
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
