/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:38 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/20 12:00:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_getintsize(int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_revstr(char *s)
{
	char	*sr;
	char	temp;
	size_t	c1;
	size_t	c2;

	c1 = 0;
	c2 = ft_strlen(s);
	sr = s;
	if (s[c1] == '-')
		c1++;
	while (c1 < c2)
	{
		temp = s[c1];
		s[c1] = s[c2];
		s[c2] = temp;
	}
	return (sr);
}

char	*ft_strnbr(int nb)
{
	char	*sr;
	int		len;

	len = ft_getintsize(nb);
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	sr[len + 1] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		sr[0] = '-';
	}
	while (len)
	{
		sr[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (sr);
}

char	*ft_itoa(int n)
{
	char	*itoa;

	if (n == 0)
		return (ft_strdup("0"));
	else if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	else if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	itoa = ft_strnbr(n);
	if (!itoa)
		return (0);
	return (itoa);
}
