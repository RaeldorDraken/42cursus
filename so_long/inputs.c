/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/03 12:28:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	key_inputs(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{	
		free(vars->level);
		mlx_destroy_window(vars->mlx, vars->win);
	}
	else if (keycode == 2)
		vars->plx += 64;
	else if (keycode == 0)
		vars->plx -= 64;
	else if (keycode == 1)
		vars->ply += 64;
	else if (keycode == 13)
		vars->ply -= 64;
	else
	{
		printf("KeyPressed %d\n", keycode);
		printf("x:%d y:%d\n", vars->plx, vars->ply);
	}
	return (0);
}

int	render_frame(t_vars *vars)
{
	int		tile_x;
	int		tile_y;

	tile_y = 0;
	while (tile_y < (vars->maph * 64))
	{
		tile_x = 0;
		while (tile_x < (vars->mapw * 64))
		{
			if (check_tile(vars->level[tile_y / 64][tile_x / 64]))
				mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[2],
					tile_x, tile_y);
			else
				mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[0],
					tile_x, tile_y);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->spr[1],
				vars->plx, vars->ply);
			tile_x += 64;
		}
		tile_y += 64;
	}
	return (0);
}
