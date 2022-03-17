/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:49:18 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/17 12:30:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*sp_putstr(char *str)
{
	int	len;

	len = -1;
	if (str[0] == '%')
	{
		write(1, &str[0], 1);
		len ++;
	}
	while (str[++len])
	{
		if (str[len] != '%')
		{
			write(1, &str[len], 1);
		}
		else
			return ((char *)(str + len));
	}
	return ((char *)(str + len));
}

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
}
