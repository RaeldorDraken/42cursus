/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoibase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int	convert(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int	atoi_base(const char *str, int str_base)
{
	int	sign;
	int	result;

	result = 0;
	while (*str <= 32)
		str ++;
	if (*str == '-')
	{
		sign = -1;
		str ++;
	}
	else
		sign = 1;
	while (*str)
	{
		result = result * str_base + convert(*str);
		str ++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	if (ac == 3)
		printf("result: %d\n", atoi_base(av[1], atoi(av[2])));
	
}
