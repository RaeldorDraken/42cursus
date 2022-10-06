/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:22:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/10/06 12:29:23 by eros-gir         ###   ########.fr       */
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

int	ft_sort_b(t_stks *lists, long int target)
{
	int	i;

	i = -1;
	if (lists->size_b < 2)
		return (i);
	if (target == -9999999999)
	{
		while (++i < lists->size_b)
		{
			if (lists->b[i] < target)
				target = lists->b[i];
		}
	}
	i = -1;
	while (++i < lists->size_b)
	{
		if (lists->b[i] == target)
			break ;
	}
	if (i > lists->size_b / 2)
		return (lists->size_b - i);
	else
		return (i);
}

void	test_funct(t_stks *lists, char type)
{
	int	i;

	i = -1;
	if (type == 'b')
		ft_putendl_fd("Order B: ", 1);
	else if (type == 't')
		ft_putendl_fd("Order T: ", 1);
	while (++i < lists->size_b)
	{
		ft_putnbr_fd(lists->b[i], 1);
		ft_putchar_fd(' ', 1);
	}
	ft_putendl_fd("sale", 1);
}

long int	ft_check_nearest(t_stks *lists, long int hold)
{
	int			i;
	long int	result;
	long int	temp;

	i = -1;
	temp = lists->b[0];
	while (++i < lists->size_b)
	{
		if (temp > lists->b[i])
			temp = lists->b[i];
	}
	if (temp > hold)
		return (9999999999);
	else
	{
		result = hold;
		while (--result > temp)
		{
			i = -1;
			while (++i < lists->size_b)
			{
				if (lists->b[i] == result)
					return (result);
			}
		}
	}
	return (result);
}

void    ft_pa_bottom(t_stks *lists)
{
    int i;
	long int	temp;

	temp = ft_check_nearest(lists, lists->hold_bot);
	ft_putnbr_fd(temp, 1);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(lists->hold_top, 1);
	i = ft_sort_b(lists, temp);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (lists->a[0] != lists->hold_bot)
	{
		if (i -- >= 0)
		{
			ft_rrr(lists);
			test_funct(lists, 'b');
		}
		else
			ft_rra(lists);
	}
	while (i -- >= 0)
	{
		ft_rrb(lists);
		test_funct(lists, 'b');
	}
	ft_pb(lists);
}

void	ft_pa_top(t_stks *lists)
{
	int			i;
	long int	temp;

	temp = ft_check_nearest(lists, lists->hold_top);
	ft_putnbr_fd(temp, 1);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(lists->hold_top, 1);
	i = ft_sort_b(lists, temp);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(i, 1);
	ft_putchar_fd('\n', 1);
	while (lists->a[0] != lists->hold_top)
	{
		if (i -- >= 0)
		{
			ft_rr(lists);
			test_funct(lists, 't');
		}
		else
			ft_ra(lists);
	}
	while (i -- >= 0)
	{
		ft_rb(lists);
		test_funct(lists, 't');
	}
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
