/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:20:48 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 16:43:45 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print(char *op, t_stack **s)
{
	int		i;
	char	*str;

	str = NULL;
	str = join(str, sdup("--------------------------------\n"));
	str = join(str, op);
	str = join(str, to_str('\n'));
	i = 0;
	while (i < s[0]->size || i < s[1]->size)
	{
		if (i < s[0]->size)
			str = join(str, ft_itoa(s[0]->values[i]));
		else
			str = join(str, to_str(' '));
		if (i < s[1]->size)
		{
			str = join(str, sdup("     "));
			str = join(str, ft_itoa(s[1]->values[i]));
		}
		str = join(str, to_str('\n'));
		i++;
	}
	str = join(str, sdup("- -\na b\n"));
	ds(str);
	free(str);
}

void	ds(char *str)
{
	write(1, "|", 1);
	ft_putstr_fd(str, 1);
	write(1, "|\n", 2);
}

void	di(int i)
{
	write(1, "|", 1);
	ft_putnbr_fd(i, 1);
	write(1, "|\n", 2);
}
