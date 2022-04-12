/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 10:22:07 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/12 11:48:27 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"utilslib.h"

char	**map_buffer(char *filename, int height)
{
	int		i;
	char	**map;
	int		fd;

	i = 0;
	map = ft_calloc(sizeof(char *), height);
	fd = open(filename, O_RDONLY);
	if (!map)
	{
		free(map);
		return (NULL);
	}
	while (i < height)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free(map);
			return (NULL);
		}
		i ++;
	}
	close(fd);
	return (map);
}

//Error formatting:
//	 0 everything fine.
//	-1 error in check_size.
//	-2 error in side walls.
//	-3 error in player/exit/collectible count.
int	check_map(char *filename)
{
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
	if (height < 0)
		return (-1);
	map = map_buffer(filename, height);
	if (!map)
		return (-4);
	errorno = check_walls(map, height);
	if (errorno < 0)
		return (errorno);
	errorno = check_conditions(map, height);
	if (errorno < 0)
		return (errorno);
	free(map);
	return (0);
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
