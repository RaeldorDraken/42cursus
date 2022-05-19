/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:37:09 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/15 14:15:02 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	sx(t_stack *x);

/*
 * swap a - intercambia los dos primeros elementos encima del stack a.
 * No hace nada si hay uno o menos elementos.
 */
t_stack	**sa(t_stack **s)
{
	if (s && s[0]->size > 1)
	{
		sx(s[0]);
		s[0]->result = join(s[0]->result, sdup("sa\n"));
	}
	return (s);
}

/*
 * swap b - intercambia los dos primeros elementos encima del stack b. 
 * No hace nada si hay uno o menos elementos.
 */
t_stack	**sb(t_stack **s)
{
	if (s && s[1]->size > 1)
	{
		sx(s[1]);
		s[0]->result = join(s[0]->result, sdup("sb\n"));
	}
	return (s);
}

/*
 * swap a y swap b a la vez.
 */
t_stack	**ss(t_stack **s)
{
	if (s)
	{
		sx(s[0]);
		sx(s[1]);
		if (s[0]->size > 1 || s[1]->size > 1)
		s[0]->result = join(s[0]->result, sdup("ss\n"));
	}
	return (s);
}

/*
 * swap - intercambia los dos primeros elementos encima del stack x.
 * No hace nada si hay uno o menos elementos.
 */
static void	sx(t_stack *x)
{
	int	aux;

	if (x->size > 1)
	{
		aux = x->values[0];
		x->values[0] = x->values[1];
		x->values[1] = aux;
	}
}
