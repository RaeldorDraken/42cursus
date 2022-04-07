/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/07 13:04:43 by eros-gir         ###   ########.fr       */
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
	int len;

	i = 0;
	len = ft_strlen(*map)-1;
	printf("%d\n", len);
	while (i < count && map[i])
	{
		if (i == 0 || i == count)
		{
			if (!ft_strchr(map[i], '1'))
				return (-2);
		}
		else
		{
			if (map[i][0] != '1' && map[i][len] != '1')
				return (-2);
		}
		i ++;
	}
	return (0);
}

//Error formatting:
//	 0 everything fine.
//	-1 error in check_size.
//	-2 error in side walls.
//	-3 error in player/exit/collectible count.
int	check_map(char *filename)
{
	int		line_count;
	int		height;
	int		fd;
	int		errorno;
	char	**map;

	fd = open(filename, O_RDONLY);
	errorno = 0;
	if (!fd)
		return (-4);
	height = check_size(fd);
	close(fd);
	if (height > 0)
		printf("Height: %d\n", height);
	else if (height < 0)
		return (-1);
	map = ft_calloc(sizeof(char *), height);
	fd = open(filename, O_RDONLY);
	line_count = 0;
	while (line_count < height)
	{
		map[line_count] = get_next_line(fd);
		if (!map[line_count])
		{
			printf("not reading\n");
			return (-4);
		}
		printf("getting line %d: %s", line_count, map[line_count]);
		line_count ++;
	}
	errorno = check_walls(map, height);
	if (errorno < 0)
		return (errorno);
	free(map);
	close(fd);
	return (0);
}

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

int	main(int ac, char **av)
{
	int	errorno;

	if (ac < 2)
	{
		printf("No map argument given!\n");
		return (1);
	}
	errorno = check_map(av[1]);
	if (errorno < 0)
	{
		error_handle(errorno);
		return (1);
	}
}
