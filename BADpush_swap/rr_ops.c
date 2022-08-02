/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:29:33 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/15 16:22:43 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	rrx(t_stack *x);

/*
 * reverse rotate a - desplaza hacia abajo todos los elementos del stack a
 * una posición, de forma que el último elemento se convierte en el primero.
 */
t_stack	**rra(t_stack **s)
{
	if (s && s[0]->size > 1)
	{
		rrx(s[0]);
		s[0]->result = join(s[0]->result, sdup("rra\n"));
	}
	return (s);
}

/*
 * reverse rotate b - desplaza hacia abajo todos los elementos del stack b 
 * una posición, de forma que el último elemento se convierte en el primero.
 */
t_stack	**rrb(t_stack **s)
{
	if (s && s[1]->size > 1)
	{
		rrx(s[1]);
		s[0]->result = join(s[0]->result, sdup("rrb\n"));
	}
	return (s);
}

/*
 * reverse rotate a y reverse rotate b 
 */
t_stack	**rrr(t_stack **s)
{
	if (s)
	{
		rrx(s[1]);
		rrx(s[0]);
		if (s[0]->size > 1 || s[1]->size > 1)
		s[0]->result = join(s[0]->result, sdup("rrr\n"));
	}
	return (s);
}

/*
 * rotate x - desplaza hacia arriba todos los elementos del stack x una posición,
 * de forma que el primer elemento se convierte en el último.
 */
static void	rrx(t_stack *x)
{
	int	aux;
	int	i;

	if (x->size > 1)
	{
		i = x->size - 1;
		aux = x->values[i];
		while (i > 0)
		{
			x->values[i] = x->values[i - 1];
			i--;
		}
		x->values[i] = aux;
	}
}
