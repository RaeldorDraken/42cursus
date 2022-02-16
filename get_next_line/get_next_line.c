/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:01 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/16 19:29:44 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*line_next = NULL;
	int			read_flag;

	line = NULL;
	read_flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_calloc(sizeof (char), BUFFER_SIZE + 1);
	buffer = "BUFFER WORKS";
	if (!buffer)
		return (NULL);
	while (ft_strchr(line_next, '\n') == NULL && read_flag != 0)
	{
		read_flag = read(fd, &buffer, BUFFER_SIZE);
		if (read_flag <= 0)
			break ;
		buffer[read_flag] = '\0';
		line_next = ft_strjoin(line_next, buffer);
	}
	line = buffer;
	free(buffer);
	return (line);
}
