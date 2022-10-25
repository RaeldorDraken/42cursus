/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithmic2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:38:13 by eros-gir          #+#    #+#             */
/*   Updated: 2022/10/25 11:51:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

int	ft_ra_nbr_moves(t_stks *lists)
{
	int	i;
	int	j;

	i = 0;
	while (i < lists->size_a)
	{
		j = -1;
		while (++j < 20)
		{
			if (lists->a[i] == lists->chunk[j])
				return (i);
		}
		i ++;
	}
	return (lists->size_a);
}

int	ft_rra_nbr_moves(t_stks *lists)
{
	int	i;
	int	j;

	i = 1;
	while (i < lists->size_a)
	{
		j = -1;
		while (++j < 20)
		{
			if (lists->a[lists->size_a - i] == lists->chunk[j])
				return (i);
		}
		i ++;
	}
	return (lists->size_a);
}

long int	ft_set_target(t_stks *lists, long int target)
{
	int	i;

	i = -1;
	if (target == 9999999999)
	{
		while (++i < lists->size_b)
		{
			if (lists->b[i] < target)
				target = lists->b[i];
		}
	}
	return (target);
}

int	ft_sort_b(t_stks *lists, long int target, long int hold)
{
	int	i;
	int	buffer;

	i = -1;
	buffer = 1;
	if (lists->size_b < 2)
		return (i);
	while (++i < lists->size_b)
	{
		if (lists->b[i] < hold)
		{
			buffer = 0;
			break ;
		}
	}
	target = ft_set_target(lists, target);
	i = -1;
	while (++i < lists->size_b)
	{
		if (lists->b[i] == target)
			break ;
	}
	return (i + buffer);
}

long int	ft_check_nearest(t_stks *lists, long int hold, long int t, int i)
{
	long int	result;

	while (++i < lists->size_b)
	{
		if (t > lists->b[i])
			t = lists->b[i];
	}
	if (t > hold)
		return (9999999999);
	else
	{
		result = hold;
		while (--result > t)
		{
			i = -1;
			while (++i < lists->size_b)
			{
				if (lists->b[i] == result)
					return (result);
			}
		}
	}
	return (result);
}
