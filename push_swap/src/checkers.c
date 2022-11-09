/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:31:59 by eros-gir          #+#    #+#             */
/*   Updated: 2022/11/09 11:09:57 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/pslib.h"

void	ft_check_cases(t_stks *lists)
{
	if (ft_is_ordered(lists))
		return ;
	if (lists->size_a == 2 && lists->a[0] > lists->a[1])
		ft_sa(lists);
	else if (lists->size_a == 3)
		ft_case_three(lists);
	else if (lists->size_a > 3 && lists->size_a < 6)
		ft_case_five(lists);
	else if (lists->size_a > 5)
		ft_radix_sort(lists);
}

void	ft_check_each_input(char *input)
{
	size_t	i;

	i = 0;
	if (input[0] == '\0')
		error_terminate();
	while (input[i] != '\0' && i < ft_strlen(input))
	{
		if (ft_isdigit(input[i]) == 0 && input[i] != '-')
			error_terminate();
		if (i > 0 && input[i] == '-')
			error_terminate();
		if (input[0] == '-' && input[1] == '0')
			error_terminate();
		if (input[0] == '0' && input[1] != '\0')
			error_terminate();
		i++;
	}
}

void	ft_check_input(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		ft_check_each_input(av[i]);
		if (ft_latoi(av[i]) > (long int)INT_MAX
			|| ft_latoi(av[i]) < (long int)INT_MIN)
			error_terminate();
		j = 0;
		while (av[++j] != NULL)
		{
			if (!ft_strncmp(av[i], av[j], 11) && i != (int)j)
				error_terminate();
		}
	}
}
