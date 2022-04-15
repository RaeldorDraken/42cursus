/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:35 by eros-gir         ###   ########.fr       */
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
	int	errorno;

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
}
