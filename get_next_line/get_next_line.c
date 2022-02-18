/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:04:01 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/18 19:01:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*line_next;
	int			read_flag;

	line = NULL;
	buffer = NULL;
	read_flag = 1;
	if (fd < 0)
		return (NULL);
	if ((line_next &&  !ft_strchr(line_next, '\n')) || !line_next)
	{
		buffer = (char *)ft_calloc(sizeof (char), BUFFER_SIZE + 1);
		while (ft_strchr(buffer, '\n') == NULL && read_flag > 0)
		{
			read_flag = read(fd, buffer, BUFFER_SIZE);
			if (read_flag <= 0)
			{
				free(buffer);
				return (NULL);
			}
			else
			{
				buffer[read_flag] = '\0';
				line_next = ft_strjoin(line_next, buffer);
			}
		}
	}
	if (!line_next)
	{
		return (NULL);
	}
	line = buffer;
	free(buffer);
	return (line);
}
