/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/01 11:48:09 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_ra_work(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	i = 0;
	temp = lists->a[0];
	gtemp = lists->ga[0];
	if (lists->size_a == 1)
		return ;
	while (++i < lists->size_a)
	{
		lists->a[i - 1] = lists->a[i];
		lists->ga[i - 1] = lists->ga[i];
	}
	lists->a[i - 1] = temp;
	lists->ga[i - 1] = gtemp;
	lists->steps ++;
}

void	ft_rb_work(t_stks *lists)
{
	int	temp;
	int	gtemp;
	int	i;

	i = 0;
	temp = lists->b[0];
	gtemp = lists->gb[0];
	if (lists->size_b == 1)
		return ;
	while (++i < lists->size_b)
	{
		lists->b[i - 1] = lists->b[i];
		lists->gb[i - 1] = lists->gb[i];
	}
	lists->b[i - 1] = temp;
	lists->gb[i - 1] = gtemp;
	lists->steps ++;
}

void	ft_ra(t_stks *lists)
{
	ft_ra_work(lists);
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stks *lists)
{
	ft_rb_work(lists);
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stks *lists)
{	
	ft_ra_work(lists);
	ft_rb_work(lists);
	ft_putendl_fd("rr", 1);
}
