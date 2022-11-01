/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:50 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/01 11:48:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_sa_work(t_stks *lists)
{
	int	temp;
	int	gtemp;

	if (lists->size_a <= 1)
		return ;
	temp = lists->a[1];
	gtemp = lists->ga[1];
	lists->a[1] = lists->a[0];
	lists->ga[1] = lists->ga[0];
	lists->a[0] = temp;
	lists->ga[0] = gtemp;
	lists->steps ++;
}

void	ft_sb_work(t_stks *lists)
{
	int	temp;
	int	gtemp;

	if (lists->size_b <= 1)
		return ;
	temp = lists->b[1];
	gtemp = lists->gb[1];
	lists->b[1] = lists->b[0];
	lists->gb[1] = lists->gb[0];
	lists->b[0] = temp;
	lists->gb[0] = gtemp;
	lists->steps ++;
}

void	ft_sa(t_stks *lists)
{
	ft_sa_work(lists);
	ft_putendl_fd("sa", 1);
}

void	ft_sb(t_stks *lists)
{
	ft_sb_work(lists);
	ft_putendl_fd("sb", 1);
}

void	ft_ss(t_stks *lists)
{
	ft_sa_work(lists);
	ft_sb_work(lists);
	ft_putendl_fd("ss", 1);
}
