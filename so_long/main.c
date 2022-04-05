/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/05 13:09:00 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

void	draw_square(t_data *data, int x, int y, int w, int h, int color)
{
	int startx;

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
	int	red = 0;
	int	green = 0;
	int	blue = 0;

	color = rgbencode(red, green, blue);
	x = 0;
	y = 0;
	while(x < w)
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
		color = rgbencode(red, green, blue);
		x ++;
	}
}

//void	draw_circle(t_data *data, int x, int y, int rad, int color)

int	main(void)
{
	void	*mlxptr;
	void	*mlx_win;
	t_data	img;

	mlxptr = mlx_init();
	mlx_win = mlx_new_window(mlxptr, 1280, 720, "TEST WINDOW");
	img.img = mlx_new_image(mlxptr, 1280, 720);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.linelen, &img.endian);
	draw_gradient(&img, 1280, 720);
	draw_square(&img, 640, 360, 64, 64, 0x00FF0000);
	mlx_put_image_to_window(mlxptr, mlx_win, img.img, 0, 0);
	mlx_loop(mlxptr);
}
