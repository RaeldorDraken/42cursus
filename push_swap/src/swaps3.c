/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/15 12:30:39 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_sa(t_stks *lists)
{
	int	temp;

	if (lists->size_a <= 1)
		return ;
	temp = lists->a[1];
	lists->a[1] = lists->a[0];
	lists->a[0] = temp;
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stks *lists)
{
	int	temp;

	if (lists->size_b <= 1)
		return ;
	temp = lists->b[1];
	lists->b[1] = lists->b[0];
	lists->b[0] = temp;
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stks *lists)
{
	int	temp;

	if (lists->size_a <= 1)
	{
		temp = lists->a[1];
		lists->a[1] = lists->a[0];
		lists->a[0] = temp;
	}
	if (lists->size_b > 1)
	{
		temp = lists->b[1];
		lists->b[1] = lists->b[0];
		lists->b[0] = temp;
	}
	ft_putendl_fd("ss", 1);
}

void	ft_pa(t_stks *lists)
{
	int	temp;
	int	i;

	if (lists->size_b < 1)
		return ;
	i = lists->size_a;
	temp = lists->b[0];
	while (i > 0)
	{
		lists->a[i] = lists->a[i - 1];
		i --;
	}
	lists->a[0] = temp;
	i = -1;
	while (++i < lists->size_b - 1)
		lists->b[i] = lists->b[i + 1];
	lists->size_b --;
	lists->size_a ++;
	ft_putendl_fd("pa", 1);
}

void	ft_pb(t_stks *lists)
{
	int	temp;
	int	i;

	if (lists->size_a < 1)
		return ;
	i = lists->size_b;
	temp = lists->a[0];
	while (i >= 0)
	{
		lists->b[i] = lists->b[i - 1];
		i --;
	}
	lists->b[0] = temp;
	i = -1;
	while (++i < lists->size_a - 1)
		lists->a[i] = lists->a[i + 1];
	lists->size_a --;
	lists->size_b ++;
	ft_putendl_fd("pb", 1);
}
