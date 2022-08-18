/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:05:54 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/18 18:49:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_ra(t_stks *lists)
{
	int	temp;
	int	i;

	i = -1;
	temp = lists->a[0];
	while (++i < lists->size_a - 1)
		lists->a[i] = lists->a[i + 1];
	lists->a[i] = temp;
	lists->steps ++;
	ft_putendl_fd("ra", 1);
}

void	ft_rb(t_stks *lists)
{
	int	temp;
	int	i;

	i = -1;
	temp = lists->b[0];
	while (++i < lists->size_b - 1)
		lists->b[i] = lists->b[i + 1];
	lists->b[i] = temp;
	lists->steps ++;
	ft_putendl_fd("rb", 1);
}

void	ft_rr(t_stks *lists)
{
	int	temp;
	int	i;

	i = -1;
	temp = lists->a[0];
	while (++i < lists->size_a - 1)
		lists->a[i] = lists->a[i + 1];
	lists->a[i] = temp;
	i = -1;
	temp = lists->b[0];
	while (++i < lists->size_b - 1)
		lists->b[i] = lists->b[i + 1];
	lists->b[i] = temp;
	lists->steps ++;
	ft_putendl_fd("rr", 1);
}
