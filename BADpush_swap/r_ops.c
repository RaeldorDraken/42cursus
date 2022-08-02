/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:29:33 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 16:32:20 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	rx(t_stack *x);

/*
 * rotate a - desplaza hacia arriba todos los elementos del stack a una posición,
 * de forma que el primer elemento se convierte en el último.
*/
t_stack	**ra(t_stack **s)
{
	if (s && s[0]->size > 1)
	{
		rx(s[0]);
		s[0]->result = join(s[0]->result, sdup("ra\n"));
	}
	return (s);
}

/*
 * rotate b - desplaza hacia arriba todos los elementos del stack b una posición,
 * de forma que el primer elemento se convierte en el último.
 */
t_stack	**rb(t_stack **s)
{
	if (s && s[1]->size > 1)
	{
		rx(s[1]);
		s[0]->result = join(s[0]->result, sdup("rb\n"));
	}
	return (s);
}

/*
 * rotate a y rotate b 
 */
t_stack	**rr(t_stack **s)
{
	if (s)
	{
		rx(s[0]);
		rx(s[1]);
		if (s[0]->size > 1 || s[1]->size > 1)
			s[0]->result = join(s[0]->result, sdup("rr\n"));
	}
	return (s);
}

/*
 * rotate x - desplaza hacia arriba todos los elementos del stack x una posición,
 * de forma que el primer elemento se convierte en el último.
 */
static void	rx(t_stack *x)
{
	int	aux;
	int	i;

	if (x->size > 1)
	{
		aux = x->values[0];
		i = 1;
		while (i < x->size)
		{
			x->values[i - 1] = x->values[i];
			i++;
		}
		x->values[i - 1] = aux;
	}
}
