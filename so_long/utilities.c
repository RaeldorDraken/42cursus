/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:13:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/12 11:49:44 by eros-gir         ###   ########.fr       */
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

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->linelen + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	rgbencode(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}
