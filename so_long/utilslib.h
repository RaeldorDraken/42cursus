/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/05 12:21:57 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSLIB_H
# define UTILSLIB_H

# include"libft/libft.h"
# include"minilibx/mlx.h"
# include<stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_data;

void	put_pixel(t_data *data, int x, int y, int color);
int		rgbencode(uint8_t red, uint8_t green, uint8_t blue);

#endif
