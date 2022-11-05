/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:45:03 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/05 15:46:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_radix_sort(t_stks *lists)
{
	int	steps;
	int	max_size;
	int	i;
	int	j;

	steps = 0;
	i = -1;
	max_size = lists->size_a;
	while ((max_size - 1) >> steps != 0)
		steps++;
	while (++i < steps)
	{
		j = -1;
		while (++j < max_size)
		{
			if (((lists->ga[0] >> i) & 1) == 1)
				ft_ra(lists);
			else
				ft_pb(lists);
		}
		while (lists->size_b > 0)
			ft_pa(lists);
	}
}
