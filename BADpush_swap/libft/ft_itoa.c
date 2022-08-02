/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:17:34 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/03 15:21:51 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_c(char *c, long aux, int len);

static int	int_len(long n);

char	*ft_itoa(int n)
{
	char	*c;
	int		len;
	long	aux;

	aux = n;
	len = int_len(aux);
	c = malloc(len + 1);
	if (c == NULL)
		return (NULL);
	c = ft_memset(c, '0', len);
	c[len] = '\0';
	if (n < 0)
	{	
		aux *= -1;
		c[0] = '-';
	}	
	fill_c(c, aux, len);
	return (c);
}

static void	fill_c(char *c, long aux, int len)
{
	while (--len >= 0)
	{
		c[len] += aux % 10;
		aux /= 10;
	}
}

static int	int_len(long n)
{
	int		len;

	len = 0;
	if (n <= 0)
	{	
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
