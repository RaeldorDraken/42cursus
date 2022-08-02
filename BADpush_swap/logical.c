/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:42:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/23 13:00:15 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	logical_1a(t_stack **s);

void	logical_2a(t_stack **s);
void	logical_2b(t_stack **s);

void	push_part(t_stack **s, int n, int part);

void	logical(t_stack **s)
{
	if (s[0]->size <= 15)
	{
		while (!sorted(s[0]))
		{
			logical_1a(s);
			logical_2b(s);
		}	
	}
	else
	{	
		logical_2a(s);
		logical_2b(s);
	}
}

void	logical_2b(t_stack **s)
{
	int	max;
	int	next_max;

	while (s[1]->size > 0)
	{
		max = get_max(s[1]);
		next_max = get_next_max(s[1], max);
		while (s[1]->values[0] != max)
		{	
			if (s[1]->values[0] == next_max)
				pa(s);
			if (s[1]->values[0] == max)
				break ;
			if (get_pos(s[1], max) > s[1]->size / 2)
				rrb(s);
			else
				rb(s);
		}
		pa(s);
		if (s[0]->values[1] < s[0]->values[0])
			sa(s);
	}
}

void	logical_2a(t_stack **s)
{
	int	part;
	int	n;
	int	max;

	max = get_max(s[0]);
	if (s[0]->size < 15)
		n = 1;
	if (s[0]->size <= 150)
		n = 5;
	else
		n = 8;
	part = get_max(s[0]) / n;
	push_part(s, n, part);
	while (s[0]->size > 1)
	{
		if (s[0]->values[0] == max)
			rra(s);
		pb(s);
	}
}

void	logical_1a(t_stack **s)
{
	int	min;

	min = get_min(s[0]);
	if (s[0]->size > 3 && get_pos(s[0], min) == s[0]->size - 1)
		rra(s);
	while (1)
	{
		if (sorted(s[0]))
			break ;
		while (s[0]->values[0] == min)
		{
			pb(s);
			min = get_next_min(s[0], min);
		}
		if (!save_rotate(s))
			if (!save_swap(s))
				pb(s);
	}
}

void	push_part(t_stack **s, int n, int part)
{
	int	max;
	int	offset;

	offset = 0;
	max = get_max(s[0]);
	while (n-- > 0)
	{
		while (exist_less_than(s, part + offset))
		{
			if (s[0]->values[0] > part + offset)
				ra(s);
			else
			{
				pb(s);
				if (s[1]->values[0] <= (part / 2) + offset)
				{
					if (s[0]->values[0] > part + offset)
						rr(s);
					else
						rb(s);
				}
			}
		}
		offset += part;
	}
}
