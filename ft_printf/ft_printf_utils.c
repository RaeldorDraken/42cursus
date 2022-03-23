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

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	ft_putstr_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len ++;
	}
	return (len);
}

int	ft_putnbr_hex(long long int nbr, int ptr, int cap, int len)
{
	char	*hexbase;

	if (nbr < 0)
	{
		if (!ptr)
		{
			len ++;
			ft_putchar('-');
		}
		nbr = -nbr;
	}
	if (!cap)
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	if (ptr)
		len += write(1, "0x", 2);
	if (nbr >= 16)
		len += ft_putnbr_hex(nbr / 16, 0, cap, len);
	nbr = nbr % 16;
	ft_putchar(hexbase[nbr]);
	return (len);
}
