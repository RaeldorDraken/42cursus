/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	ft_numlen(int n)
{
	int len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len ++;
	}
	while (n >= 10)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

int	ft_pwr(int pwr)
{
	int	i;

	i = 1;
	if (pwr == 1)
		return (1);
	while (pwr > 1)
	{
		i *= 10;
		pwr --;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*sr;
	int		i;
	int		len;
	int		len2;

	i = 0;
	len = ft_numlen(n);
	len2 = len;
	sr = malloc(sizeof(char) * (len + 1));
	if (!sr)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		sr[i] = '-';
		i ++;
		len --;
	}
	while (i < len2)
	{
		sr[i] =  ((n / ft_pwr(len)) % 10) + '0';
		len --;
		i ++;
	}
	sr[++i] = '\0';
	return (sr);
}

int	main(void)
{
	int n = -4321598;

	printf("number: %d\nstring: %s\n", n, ft_itoa(n));
	return (0);
}
