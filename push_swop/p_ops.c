/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:14:09 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/14 15:46:40 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static void	pxz(t_stack *x, t_stack *z);

/*
 * push a - toma el primer elemento del stack b y lo pone encima del stack a.
 * No hace nada si b está vacío.
 */
t_stack	**pa(t_stack **s)
{
	if (s)
	{
		pxz(s[1], s[0]);
		s[0]->result = join(s[0]->result, sdup("pa\n"));
	}
	return (s);
}

/*
 * push a - toma el primer elemento del stack b y lo pone encima del stack b.
 * No hace nada si b está vacío. 
 */
t_stack	**pb(t_stack **s)
{
	if (s)
	{
		pxz(s[0], s[1]);
		s[0]->result = join(s[0]->result, sdup("pb\n"));
	}
	return (s);
}

/*
 * push xz - toma el primer elemento del stack x y lo pone encima del stack z.
 * No hace nada si b está vacío. 
 */
static void	pxz(t_stack *x, t_stack *z)
{
	int	aux;
	int	i;

	if (x->size > 0)
	{
		aux = x->values[0];
		i = 1;
		while (i < x->size)
		{
			x->values[i - 1] = x->values[i];
			i++;
		}
		x->size--;
		i = z->size;
		while (i > 0)
		{
			z->values[i] = z->values[i - 1];
			i--;
		}
		z->size++;
		z->values[0] = aux;
	}
}
