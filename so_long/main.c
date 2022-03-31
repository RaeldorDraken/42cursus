/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/31 12:03:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft/libft.h"
#include"minilibx/mlx.h"
#include<stdio.h>

int	main(void)
{
	void	*mlxptr;
	int		count;

	count = 1000;
	mlxptr = mlx_init();
	if (!mlxptr)
	{
		printf("ERROR ON INIT");
		return (0);
	}
	if (!mlx_new_window(mlxptr, 1280, 720, "TEST WINDOW"))
	{
		printf("ERROR ON CREATE WINDOW");
		return (0);
	}
	while (count > 0)
		count --;
}
