/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/26 12:51:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSLIB_H
# define UTILSLIB_H

# include"libft/libft.h"
# include"minilibx/mlx.h"
# include<stdio.h>
# include<fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
}	t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

void	put_pixel(t_data *data, int x, int y, int color);
int		rgbencode(int alpha, int red, int green, int blue);
int		rgbdecode(char type, int value);
char	*get_next_line(int fd);
int		ft_strchk(char *s, int c);
int		check_conditions(char **map, int height);
int		check_map(char *filename);
char	**map_buffer(char *filename, int height);
int		check_walls(char **map, int count);
int		check_size(int fd);
void	error_handle(int number);
int		exit_game(int keycode, t_vars *vars);;

#endif
