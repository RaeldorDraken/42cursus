/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:49:18 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/29 10:52:14 by eros-gir         ###   ########.fr       */
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
int	ft_putnbr_base(unsigned long int nbr, char *base, int len)
{
	unsigned long		bsize;

	bsize = ft_strlen(base);
	if (nbr >= bsize)
		len += ft_putnbr_base(nbr / bsize, base, len);
	nbr = nbr % bsize;
	ft_putchar(base[nbr]);
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*itoa;
	size_t	len;
	size_t	l;

	if ((int)n < 0)
		len = 10;
	else
		len = ft_getintsize(n);
	itoa = ft_calloc(sizeof(char), len + 2);
	l = 0;
	if (!itoa)
		return (NULL);
	itoa[0] = '0';
	while (l < len)
	{
		itoa[l++] = (n % 10) + 48;
		n = n / 10;
	}
	return (ft_revstr(itoa));
}
