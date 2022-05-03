/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilslib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:14:05 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/03 12:27:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILSLIB_H
# define UTILSLIB_H

# include"libft/libft.h"
# include"minilibx/mlx.h"
# include<stdio.h>
# include<fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		linelen;
	int		endian;
	int		plx;
	int		ply;
	char	**level;
	int		mapw;
	int		maph;
	void	**spr;
}	t_vars;

int		render_frame(t_vars *vars);
char	*get_next_line(int fd);
int		ft_strchk(char *s, int c);
int		check_conditions(char **map, int height);
int		check_filename(char *str);
int		check_map(char *filename, t_vars *vars);
char	**map_buffer(char *filename, int height);
int		check_walls(char **map, int count);
int		check_size(int fd);
void	error_handle(int number);
int		key_inputs(int keycode, t_vars *vars);
int		check_tile(char c);

#endif
