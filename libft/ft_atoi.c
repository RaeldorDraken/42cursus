/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:17:03 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/14 14:48:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<limits.h>
#include<stdio.h>

int	ft_atoi(const char *nptr)
{
	int		len;
	int		sign;
	long int	result;

	len = 0;
	sign = 1;
	result = 0;
	if (nptr[0] == '-')
	{
		sign = -1;
		len++;
	}
	while (nptr[len] >= 48 && nptr[len] <= 57)
	{
		result = (nptr[len] - 48) + (result * 10);
		len++;
	}
	result = result * sign;
	if (result > INT_MAX || result < INT_MIN)
		return (0);
	return (result);
}
