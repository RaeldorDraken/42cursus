/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logical.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:42:17 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 16:25:19 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	save_swap(t_stack **s)
{
	int	swapable;

	swapable = check_swapable(s);
	if (swapable == 1)
		sa(s);
	if (swapable == 2)
		sb(s);
	if (swapable == 3)
		ss(s);
	if (swapable == 0 || swapable == 2)
		return (0);
	return (1);
}

int	save_rotate(t_stack **s)
{
	int	rotable;

	rotable = check_rotable(s);
	if (rotable == 1)
		ra(s);
	if (rotable == 2)
		rb(s);
	if (rotable == 3)
		rr(s);
	if (rotable == 0 || rotable == 2)
		return (0);
	return (1);
}
