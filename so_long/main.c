/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/27 12:49:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	draw_square(t_vars *vars, int x, int y, int w, int h, int color)
{
	int	startx;

	startx = x;
	w = w + x;
	h = h + y;
	while (y < h)
	{
		while (x < w)
		{
			put_pixel(vars, x, y, color);
			x ++;
		}
		x = startx;
		y ++;
	}		
}

void	draw_gradient(t_vars *vars, int w, int h)
{
	int	color;
	int	x;
	int	y;
	int	alpha = 255;
	int	red = 0;
	int	green = 0;
	int	blue = 0;

	color = rgbencode(alpha, red, green, blue);
	x = 0;
	y = 0;
	while (x < w)
	{
		while (y < h)
		{
			put_pixel(vars, x, y, color);
			y ++;
		}
		red ++;
		green ++;
		blue ++;
		y = 0;
		color = rgbencode(alpha, red, green, blue);
		x ++;
	}
}

int	check_filename(char *str)
{
	char	*chks;
	char	*cmps;
	int		len;

	cmps = ".ber";
	len = ft_strlen(str);
	chks = ft_substr(str, len - 4, len);
	if (ft_strncmp(chks, cmps, 5))
		return (-5);
	return (0);
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
		errorno = check_map(av[1]);
	if (errorno < 0)
	{
		error_handle(errorno);
		return (1);
	}
	vars.mlx = mlx_init();
	vars.plx = 64;
	vars.ply = 64;
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bpp,
			&vars.linelen, &vars.endian);
	mlx_loop_hook(vars.mlx, render_frame, &vars);
	mlx_hook(vars.win, 2, 1L<<0, key_inputs, &vars);
	mlx_loop(vars.mlx);
}
