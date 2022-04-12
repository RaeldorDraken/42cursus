/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  check_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/12 11:34:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

int	check_size(int fd)
{
	int		height;
	int		width;
	int		cwidth;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	width = ft_strlen(line);
	while (line)
	{
		cwidth = ft_strlen(line);
		line = get_next_line(fd);
		if (width != cwidth)
		{
			return (-1);
		}
		height ++;
	}
	return (height);
}

int	check_walls(char **map, int count)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(*map) - 2;
	while (i < count && map[i])
	{
		if (i == 0 || i == (count - 1))
		{
			if (ft_strchk(map[i], '0') > 0)
				return (-2);
		}
		else
		{
			if (map[i][0] != '1' || map[i][len] != '1')
				return (-2);
		}
		i ++;
	}
	return (0);
}

int	check_conditions(char **map, int height)
{
	int	i;
	int	pl;
	int	co;
	int	ex;

	i = -1;
	pl = 0;
	co = 0;
	ex = 0;
	while (++i < height)
	{
		pl += ft_strchk(map[i], 'P');
		co += ft_strchk(map[i], 'C');
		ex += ft_strchk(map[i], 'E');
	}
	if (pl != 1 || co == 0 || ex != 1)
		return (-3);
	return (0);
}

//Error formatting:
//	 0 everything fine.
//	-1 error in check_size.
//	-2 error in side walls.
//	-3 error in player/exit/collectible count.
void	error_handle(int number)
{
	printf("Error\n");
	if (number == -1)
		printf("\tThe map has the incorrect format size!");
	else if (number == -2)
		printf("\tThere is a gap on at least one side!");
	else if (number == -3)
		printf("\tThe player/collectible/exit condition is not met!");
	else
		printf("\tUNDEFINED ERROR!");
	printf("\n");
	return ;
}
