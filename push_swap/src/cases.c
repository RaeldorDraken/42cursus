/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:32:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/08/15 13:04:10 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_case_three(t_stks *lists)
{
	int	i;

	i = -1;
	if (lists->a[0] > lists->a[1])
	{
		if (lists->a[1] > lists->a[2])
		{
			ft_sa(lists);
			ft_rra(lists);
		}
		else if (lists->a[0] > lists->a[2])
			ft_ra(lists);
		else
			ft_sa(lists);
	}
	else
	{
		if (lists->a[0] > lists->a[2])
			ft_rra(lists);
		else if (lists->a[1] > lists->a[2])
		{
			ft_sa(lists);
			ft_ra(lists);
		}
	}
}

void	ft_case_five(t_stks *lists)
{
	ft_sa(lists);
	ft_sa(lists);
}

void	ft_case_algorithmic(t_stks *lists)
{	
	ft_sa(lists);
	ft_sa(lists);
}
