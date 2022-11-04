/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:22:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/04 12:13:40 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_pa_bottom(t_stks *lists)
{
	int			i;
	long int	temp;

	temp = ft_check_nearest(lists, lists->hold_bot, lists->b[0], -1);
	i = ft_sort_b(lists, temp, lists->hold_bot);
	while (lists->a[0] != lists->hold_bot)
		ft_rra(lists);
	while (i -- > 0)
		ft_rb(lists);
	ft_pb(lists);
}

void	ft_pa_top(t_stks *lists)
{
	int			i;
	long int	temp;

	temp = ft_check_nearest(lists, lists->hold_top, lists->b[0], -1);
	i = ft_sort_b(lists, temp, lists->hold_top);
	while (lists->a[0] != lists->hold_top)
	{
		if (i -- > 0)
		{
			ft_rr(lists);
		}
		else
			ft_ra(lists);
	}
	while (i -- > 0)
	{
		ft_rb(lists);
	}
	ft_pb(lists);
}

void	ft_return_to_a(t_stks *lists, int i, long int temp)
{
	while (++i < lists->size_b)
	{
		if (temp < lists->b[i])
		{
			temp = lists->b[i];
		}
	}
	i = 0;
	while (temp != lists->b[i])
		i ++;
	if (i <= lists->size_b / 2)
	{
		while (temp != lists->b[0])
			ft_rb(lists);
	}
	else
	{
		while (temp != lists->b[0])
			ft_rrb(lists);
	}
	while (lists->size_b > 0)
		ft_pa(lists);
}

void	ft_case_algorithmic(t_stks *lists)
{
	int	i;
	int	size;

	while (lists->size_a > 0)
	{
		i = -1;
		size = ft_check_chunk(lists);
		while (++i < size)
		{
			ft_set_hold_top(lists, size);
			ft_set_hold_bottom(lists, size);
			if (ft_ra_nbr_moves(lists) > ft_rra_nbr_moves(lists)
				|| lists->hold_top == INT_MAX)
				ft_pa_bottom(lists);
			else
				ft_pa_top(lists);
		}
	}
	ft_return_to_a(lists, -1, -9999999999);
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

void	ft_radix_sort(t_stks *lists)
{
	int	steps;
	int	max_size;
	int	i;
	int	j;

	steps = 0;
	i = 0;
	max_size = lists->size_a - 1;
	while (max_size >> steps != 0)
		++steps;
	while(++i < steps)
	{
		j = 0;
		while (++j < lists->size_a)
		{
			if (((lists->ga[0] >> i)&1) == 1)
				ft_ra(lists);
			else
				ft_pb(lists);
		}
		while (lists->size_b > 0)
			ft_pa(lists);
	}
}
