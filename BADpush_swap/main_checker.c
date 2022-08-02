/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:09:34 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/05/09 17:28:37 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char *argv[])
{
	char	**ops;

	if (argc < 2)
		return (0);
	if (check_input(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ops = read_ops();
	if (checker(argc, argv, ops))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	v_free(ops);
	return (0);
}
