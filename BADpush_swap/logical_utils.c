/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:42:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 17:09:42 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_max(t_stack *x)
{
	int	max;
	int	i;

	i = 0;
	max = x->values[0];
	while (i < x->size)
	{
		if (max < x->values[i])
			max = x->values[i];
		i++;
	}
	return (max);
}

int	get_min(t_stack *x)
{
	int	min;
	int	i;

	i = 0;
	min = x->values[0];
	while (i < x->size)
	{
		if (min > x->values[i])
			min = x->values[i];
		i++;
	}
	return (min);
}

int	get_next_min(t_stack *x, int min)
{
	int	new_min;
	int	i;
	int	pos;

	i = 0;
	new_min = get_max(x);
	while (i < x->size)
	{
		if (new_min > x->values[i] && x->values[i] > min)
		{
			new_min = x->values[i];
			pos = i;
		}
		i++;
	}
	return (new_min);
}

int	get_next_max(t_stack *x, int max)
{
	int	new_max;
	int	i;

	i = 0;
	new_max = get_min(x);
	while (i < x->size)
	{		
		if (new_max < x->values[i] && x->values[i] < max)
				new_max = x->values[i];
			i++;
	}
	return (new_max);
}

int	get_pos(t_stack *s, int nbr)
{
	int	pos;

	pos = 0;
	while (pos < s->size)
	{
		if (s->values[pos] == nbr)
			return (pos);
		pos++;
	}
	return (-1);
}
