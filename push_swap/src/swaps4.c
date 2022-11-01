/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/01 11:49:23 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_change_sizes(char ab, t_stks *lists)
{
	if (ab == 'a')
	{
		lists->size_b --;
		lists->size_a ++;
		lists->steps ++;
		ft_putendl_fd("pa", 1);
	}
	else if (ab == 'b')
	{
		lists->size_a --;
		lists->size_b ++;
		lists->steps ++;
		ft_putendl_fd("pb", 1);
	}
}

void	ft_pa(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	if (lists->size_b < 1)
		return ;
	i = lists->size_a;
	temp = lists->b[0];
	gtemp = lists->gb[0];
	while (i > 0)
	{
		lists->a[i] = lists->a[i - 1];
		lists->ga[i] = lists->ga[i - 1];
		i --;
	}
	lists->a[0] = temp;
	lists->ga[0] = gtemp;
	i = -1;
	while (++i < lists->size_b - 1)
	{
		lists->b[i] = lists->b[i + 1];
		lists->gb[i] = lists->gb[i + 1];
	}
	ft_change_sizes('a', lists);
}

void	ft_pb(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	if (lists->size_a < 1)
		return ;
	i = lists->size_b;
	temp = lists->a[0];
	gtemp = lists->ga[0];
	while (i >= 0)
	{
		lists->b[i] = lists->b[i - 1];
		lists->gb[i] = lists->gb[i - 1];
		i --;
	}
	lists->b[0] = temp;
	lists->gb[0] = gtemp;
	i = -1;
	while (++i < lists->size_a - 1)
	{
		lists->a[i] = lists->a[i + 1];
		lists->ga[i] = lists->ga[i + 1];
	}
	ft_change_sizes('b', lists);
}
