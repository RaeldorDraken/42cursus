/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:32:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/10/25 10:53:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_check_cases(t_stks *lists)
{
	if (lists->size_a == 2 && lists->a[0] > lists->a[1])
		ft_sa(lists);
	else if (lists->size_a == 3)
		ft_case_three(lists);
	else if (lists->size_a > 3 && lists->size_a < 6)
		ft_case_five(lists);
	else if (lists->size_a > 5)
		ft_case_algorithmic(lists);
}

int	ft_check_list_a(t_stks *lists, int type)
{
	int	i;
	int	result;

	i = -1;
	result = 0;
	if (type == 0)
	{
		while (++i < lists->size_a)
		{
			if (lists->a[result] > lists->a[i])
				result = i;
		}
	}
	else
	{
		while (++i < lists->size_a)
		{
			if (lists->a[result] < lists->a[i])
				result = i;
		}
	}
	return (result);
}

//type: 0 = smallest, 1 = biggest;
long int	ft_look_for_nbr(t_stks *lists, int type)
{
	long int	nbr;
	int			i;

	i = -1;
	nbr = 9999999999;
	if (type == 0)
	{
		while (++i < lists->size_a)
		{
			if (lists->a[i] < nbr)
				nbr = lists->a[i];
		}
	}
	else if (type == 1)
	{
		nbr = -9999999999;
		while (++i < lists->size_a)
		{
			if (lists->a[i] > nbr)
				nbr = lists->a[i];
		}
	}
	return (nbr);
}

void	ft_case_three(t_stks *lists)
{
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
	while (ft_check_list_a(lists, 0) != 0)
	{
		if (lists->a[1] == ft_look_for_nbr(lists, 0)
			|| lists->a[2] == ft_look_for_nbr(lists, 0))
			ft_ra(lists);
		else
			ft_rra(lists);
	}
	ft_pb(lists);
	while (ft_check_list_a(lists, 1) != 0)
	{
		if (lists->a[1] == ft_look_for_nbr(lists, 1)
			|| lists->a[2] == ft_look_for_nbr(lists, 1))
			ft_ra(lists);
		else
			ft_rra(lists);
	}
	ft_pb(lists);
	ft_case_three(lists);
	ft_pa(lists);
	ft_ra(lists);
	ft_pa(lists);
}
