/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/01 11:47:28 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_rra_work(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	if (lists->size_a <= 1)
		return ;
	i = lists->size_a - 1;
	temp = lists->a[i];
	gtemp = lists->ga[i];
	while (i >= 0)
	{
		lists->a[i] = lists->a[i - 1];
		lists->ga[i] = lists->ga[i - 1];
		i --;
	}
	lists->a[0] = temp;
	lists->ga[0] = gtemp;
	lists->steps ++;
}

void	ft_rrb_work(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	if (lists->size_b <= 1)
		return ;
	i = lists->size_b - 1;
	temp = lists->b[i];
	gtemp = lists->gb[i];
	while (i >= 0)
	{
		lists->b[i] = lists->b[i - 1];
		lists->gb[i] = lists->gb[i - 1];
		i --;
	}
	lists->b[0] = temp;
	lists->gb[0] = gtemp;
	lists->steps ++;
}

void	ft_rra(t_stks *lists)
{
	ft_rra_work(lists);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_stks *lists)
{
	ft_rrb_work(lists);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_stks *lists)
{
	ft_rra_work(lists);
	ft_rrb_work(lists);
	ft_putendl_fd("rrr", 1);
}
