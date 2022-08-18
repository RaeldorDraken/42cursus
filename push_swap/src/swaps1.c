/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/18 18:49:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_rra(t_stks *lists)
{
	int	temp;
	int	i;

	if (lists->size_a <= 1)
		return ;
	i = lists->size_a - 1;
	temp = lists->a[i];
	while (i >= 0)
	{
		lists->a[i] = lists->a[i - 1];
		i --;
	}
	lists->a[0] = temp;
	lists->steps ++;
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stks *lists)
{
	int	temp;
	int	i;

	if (lists->size_b <= 1)
		return ;
	i = lists->size_b - 1;
	temp = lists->b[i];
	while (i >= 0)
	{
		lists->b[i] = lists->b[i - 1];
		i --;
	}
	lists->b[0] = temp;
	lists->steps ++;
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stks *lists)
{
	int	temp;
	int	i;

	if (lists->size_a > 1)
	{
		i = lists->size_a;
		temp = lists->a[i - 1];
		while (--i >= 0)
			lists->a[i] = lists->a[i - 1];
		lists->a[0] = temp;
	}
	if (lists->size_b > 1)
	{
		i = lists->size_b;
		temp = lists->b[i - 1];
		while (--i >= 0)
			lists->b[i] = lists->b[i - 1];
		lists->b[0] = temp;
	}
	lists->steps ++;
	ft_putendl_fd("rrr", 1);
}		
