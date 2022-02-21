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

char	*get_current_line(char *s)
{
	int		i;
	char	*current;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	current = (char *)malloc((sizeof (char)) * (i + 2));
	if (!current)
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != '\n')
		current[i] = s[i];
	if (s[i] == '\n')
		current[i] = s[i];
	if (current[i] == '\n')
		i++;
	current[i] = '\0';
	return (current);
}

char	*get_read_line(int fd, char *readline)
{
	char		*buffer;
	int			flag;

	flag = 1;
	buffer = malloc((sizeof (char)) * (BUFFER_SIZE +1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(readline, '\n') && flag > 0)
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[flag] = '\0';
		readline = ft_strjoin(readline, buffer);
	}
	free(buffer);
	return (readline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_next;

	line = NULL;
	if (fd < 0)
		return (NULL);
	line_next = get_read_line(fd, line_next);
	if (!line_next)
	{
		return (NULL);
	}
	line = get_current_line(line_next);
	return (line);
}
