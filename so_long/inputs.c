/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:53:23 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/27 12:49:32 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	key_inputs(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
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
	void	*bg_img;
	int		img_width;
	int		img_height;
	void	*player;
	int		scr_w;
	int		scr_h;

	scr_h = 0;
	bg_img = mlx_png_file_to_image(vars->mlx, "./sprites/BGrock.png",
		&img_width, &img_height);
	player = mlx_png_file_to_image(vars->mlx, "./sprites/up_00.png",
		&img_width, &img_height);
	while (scr_h < 1080)
	{
		scr_w = 0;
		while (scr_w < 1920)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, bg_img, scr_w, scr_h);
			scr_w += 64;
		}
		scr_h += 64;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, player,
		vars->plx, vars->ply);
	return (0);
}
