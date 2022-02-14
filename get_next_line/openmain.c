/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:38:45 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/14 19:02:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include"get_next_line.h"

size_t	ft_file_bytes(int fd, size_t readcount)
{
	char	*stemp;
	char	c;
	size_t	count;

	count = 0;
	stemp = (char*)malloc(sizeof(char) * readcount);
	read(fd, &stemp, readcount);
	c = '\0';
	while (c != '\n')
	{
		read(fd, &c, 1);
		count++;
	}
	close(fd);
	return (count);
}

int		main(void)
{
	char	*file;
	int		fd;
	size_t	i;
	size_t	readcount;
	char	*str_char;

	file = "./test_text.txt";
	fd = open(file, O_RDONLY);
	i = 0;
	readcount = 0;
	if (fd == -1)
		return (fd);
	readcount = ft_file_bytes(fd, readcount);
	fd = open(file, O_RDONLY);
	str_char = (char*)malloc(sizeof(char) * readcount);
	while (i < readcount)
		read(fd, &str_char[i++], 1);
	printf("Frase a escribir:\n%s\n", str_char);
	free(str_char);
	close(fd);
}
