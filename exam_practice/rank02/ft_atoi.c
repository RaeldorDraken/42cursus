/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] < 32)
		i ++;
	if (str[i] == '-')
	{
		sign = -1;
		i ++;
	}
	else if (str[i] == '+')
		i ++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i ++;
	}
	return (sign * result);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("String: %s\nNumber: %d\n", av[1], ft_atoi(av[1]));
	printf("\n");
	return (0);
}
