/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:38:45 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/18 18:17:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"get_next_line.h"

int	main(void)
{
	char	*file;
	int		fd;
	char	*str_char;

	file = "./test_text.txt";
	fd = open(file, O_RDONLY);
	printf("Aqui funciona bien\n");
	str_char = get_next_line(fd);
	if (!str_char)
	{
		printf("NULL Return");
		close(fd);
		return (0);
	}
	printf("Esta es la linea 1: %s\n", str_char);
	str_char = get_next_line(fd);
	if (!str_char)
	{
		printf("NULL Return");
		close(fd);
		return (0);
	}
	printf("Esta es la linea 2: %s\n", str_char);
	str_char = get_next_line(fd);
	if (!str_char)
	{
		printf("NULL Return");
		close(fd);
		return (0);
	}
	printf("Esta es la linea 3: %s\n", str_char);
	close(fd);
}
