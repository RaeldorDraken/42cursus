/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:42:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/24 11:57:09 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	argerror(int ac)
{
	char	*arg;

	arg = ft_itoa(ac - 1);
	ft_putstr_fd("ERROR: wrong number of arguments. \n", 1);
	ft_putstr_fd("expected: 4 got: ", 1);
	ft_putstr_fd(arg, 1);
	ft_putstr_fd("\n", 1);
	free(arg);
	exit(0);
}
