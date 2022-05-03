/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/03 12:27:26 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

//sprites are	0 = background, 1 = player, 2 = walls
//				3 = collectibles, 4 = exit, 5 = enemies.
void	set_sprites(t_vars *vars)
{
	int	img_height;
	int	img_width;

	vars->spr[0] = mlx_png_file_to_image(vars->mlx, "./sprites/BGrock.png",
			&img_width, &img_height);
	vars->spr[1] = mlx_png_file_to_image(vars->mlx, "./sprites/up_00.png",
			&img_width, &img_height);
	vars->spr[2] = mlx_png_file_to_image(vars->mlx, "./sprites/FGrock.png",
			&img_width, &img_height);
	vars->spr[3] = mlx_png_file_to_image(vars->mlx, "./sprites/coin_0.png",
			&img_width, &img_height);
	vars->spr[4] = mlx_png_file_to_image(vars->mlx, "./sprites/Exit.png",
			&img_width, &img_height);
	vars->spr[5] = mlx_png_file_to_image(vars->mlx, "./sprites/up_00.png",
			&img_width, &img_height);
}

int	main(int ac, char **av)
{
	int		errorno;
	t_vars	vars;

	if (ac < 2)
	{
		error_handle(-5);
		return (1);
	}
	else
		errorno = check_filename(av[1]);
	if (errorno == 0)
		errorno = check_map(av[1], &vars);
	if (errorno < 0)
	{
		error_handle(errorno);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.spr = ft_calloc(sizeof(void **), 6);
	vars.plx = 64;
	vars.ply = 64;
	if (!vars.spr)
		return (0);
	set_sprites(&vars);
	vars.win = mlx_new_window(vars.mlx, (vars.mapw * 64),
			(vars.maph * 64), "so_long");
	vars.img = mlx_new_image(vars.mlx, (vars.mapw * 64), (vars.maph * 64));
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp,
			&vars.linelen, &vars.endian);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, key_inputs, &vars);
	mlx_loop(vars.mlx);
}
