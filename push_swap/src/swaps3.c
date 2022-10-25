/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/10/25 10:56:15 by eros-gir         ###   ########.fr       */
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
	lists->steps ++;
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
	lists->steps ++;
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
	lists->steps ++;
	ft_putendl_fd("ss", 1);
}

void	ft_sx(t_stks *lists, char stack)
{
	if (stack == 'a')
		ft_sa(lists);
	else if (stack == 'b')
		ft_sb(lists);
}
