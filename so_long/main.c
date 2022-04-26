/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/26 12:51:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	draw_square(t_data *data, int x, int y, int w, int h, int color)
{
	int	startx;

	startx = x;
	w = w + x;
	h = h + y;
	while (y < h)
	{
		while (x < w)
		{
			put_pixel(data, x, y, color);
			x ++;
		}
		x = startx;
		y ++;
	}		
}

void	draw_gradient(t_data *data, int w, int h)
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
			put_pixel(data, x, y, color);
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
	void	*mlx;
	void	*mlx_window;
	t_data	surface;
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
	mlx = mlx_init();
	vars.mlx = mlx;
	mlx_window = mlx_new_window(mlx, 1920, 1080, "so_long");
	vars.win = mlx_window;
	surface.img = mlx_new_image(mlx, 1920, 1080);
	surface.addr = mlx_get_data_addr(surface.img, &surface.bpp,
			&surface.linelen, &surface.endian);
	draw_square(&surface, 930, 510, 60, 60, rgbencode(0, 255, 0, 0));
	mlx_put_image_to_window(mlx, mlx_window, surface.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, exit_game, &vars);
	mlx_loop(mlx);
}
