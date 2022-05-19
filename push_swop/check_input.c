/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:14:40 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/13 17:03:18 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int		chek_digits(int argc, char *argv[]);
static int		chek_int_limit(int argc, char *argv[]);
static int		chek_duplicate(int argc, char *argv[]);

int	check_input(int argc, char *argv[])
{
	if (chek_digits(argc, argv))
		return (1);
	if (chek_int_limit(argc, argv))
		return (1);
	if (chek_duplicate(argc, argv))
		return (1);
	return (0);
}

static int	chek_digits(int argc, char *argv[])
{	
	int	i;
	int	u;

	i = 1;
	while (i < argc)
	{
		u = 0;
		if (argv[i][u] == '-' || argv[i][u] == '+')
			u++;
		while (1)
		{
			if (!ft_isdigit(argv[i][u]) || argv[i][0] == 0)
				return (1);
			u++;
			if (argv[i][u] == 0)
				break ;
		}
		i++;
	}
	return (0);
}

static int	chek_int_limit(int argc, char *argv[])
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (check_int(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	chek_duplicate(int argc, char *argv[])
{
	int	i;
	int	u;
	int	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		u = 1;
		while (u < argc)
		{
			if (i != u)
			{
				if (nbr == ft_atoi(argv[u]))
					return (1);
			}
			u++;
		}
		i++;
	}
	return (0);
}
