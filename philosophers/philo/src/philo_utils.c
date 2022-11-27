/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:10:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/27 15:57:52 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return(0);
}

long int	ft_atol(char *input)
{
	size_t		len;
	int			sign;
	long int	result;

	len = 0;
	sign = 1;
	result = 0;
	while (input[len] == ' ' || input[len] == '\n' || input[len] == '\t'
		|| input[len] == '\v' || input[len] == '\r' || input[len] == '\f')
		len ++;
	while (input[len] == '-' || input[len] == '+')
	{
		if (input[len] == '-')
			sign *= -1;
		len ++;
	}
	while (ft_isdigit(input[len]))
	{
		result = (input[len] - '0') + (result * 10);
		len ++;
	}
	result = result * sign;
	return (result);
}
