/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:39:08 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 19:04:55 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	check_swapable(t_stack **s)
{
	int	swapable;

	swapable = 0;
	if (s[0]->size > 1 && s[0]->values[1] < s[0]->values[0])
		swapable += 1;
	if (s[1]->size > 1 && s[1]->values[1] > s[1]->values[0])
		swapable += 2;
	return (swapable);
}

int	check_rotable(t_stack **s)
{
	int	rotable;

	rotable = 0;
	if (s[0]->size > 1 && s[0]->values[0] > s[0]->values[s[0]->size - 1])
		rotable += 1;
	if (s[1]->size > 1 && s[1]->values[0] < s[1]->values[s[1]->size - 1])
		rotable += 2;
	return (rotable);
}

int	sorted(t_stack *a)
{
	int	i;
	int	aux;

	if (a->size > 1)
	{
		i = 1;
		aux = a->values[0];
		while (i < a->size)
		{
			if (aux > a->values[i])
				return (0);
			aux = a->values[i];
			i++;
		}
		return (1);
	}	
	else
		return (1);
}

int	sorted_b(t_stack *b)
{
	int	i;
	int	aux;

	if (b->size > 1)
	{
		i = 1;
		aux = b->values[0];
		while (i < b->size)
		{
			if (aux < b->values[i])
				return (0);
			aux = b->values[i];
			i++;
		}
		return (1);
	}	
	else
		return (1);
}
