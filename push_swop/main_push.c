/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:09:50 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/16 18:06:35 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int argc, char *argv[])
{
	if (check_input(argc, argv))
		ft_putstr_fd("Error\n", 2);
	else
		push_swap(argc, argv);
	return (0);
}
