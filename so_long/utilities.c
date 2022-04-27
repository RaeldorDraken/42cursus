/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/27 10:20:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	ft_strchk(char *s, int c)
{
	int	l;
	int	i;
	int	result;

	l = ft_strlen(s)-1;
	i = 0;
	result = 0;
	while (i < l)
	{
		if (s[i] == c)
			result ++;
		i ++;
	}
	return (result);
}	

void	put_pixel(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->linelen + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
}

int	rgbencode(int alpha, int red, int green, int blue)
{
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

int	rgbdecode(char type, int value)
{
	if (type == 'a')
		return ((value >> 24) & 0xFF);
	else if (type == 'r')
		return ((value >> 16) & 0xFF);
	else if (type == 'g')
		return ((value >> 8) & 0xFF);
	else if (type == 'b')
		return (value & 0xFF);
	return (-1);
}
