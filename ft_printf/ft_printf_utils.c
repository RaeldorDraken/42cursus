/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:49:18 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/15 12:54:39 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sp_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] != '%')
			write(1, &str[len], 1);
		else
			return (len);
		len ++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		write(1, &str[len++], 1);
}
