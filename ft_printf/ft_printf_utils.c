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

//arg len is used to pass into the recursive function, always start it at 1
int	ft_putnbr_base(long long int nbr, char *base, int len)
{
	int		bsize;
	char	*decimal;

	decimal = "0123456789";
	bsize = ft_strlen(base);
	if (nbr < 0 && base == decimal)
	{
		len ++;
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= bsize)
		len += ft_putnbr_base(nbr / bsize, base, len);
	nbr = nbr % bsize;
	ft_putchar(base[nbr]);
	return (len);
}
