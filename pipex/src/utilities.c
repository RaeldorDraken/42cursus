/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:51:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/29 11:05:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

size_t	add_numb(int quotes)
{
	if (quotes <= 0)
		return (1);
	return (0);
}

char	*final_path(char **paths, char *cmd)
{
	int		i;
	char	*path;

	i = -1;
	if (ft_strrcmp(cmd, ".sh", 2) != 0)
	{
		while (paths[++i])
		{
			path = ft_strjoin(paths[i], cmd);
			if (!access(path, F_OK))
				return (path);
			free(path);
		}
	}
	else
	{
		path = ft_strdup(cmd);
		if (!access(path, X_OK))
			return (path);
	}
	return (0);
}

void	close_fds(t_pipex *pobj)
{
	close(pobj->end[0]);
	close(pobj->end[1]);
	close(pobj->infile);
	close(pobj->outfile);
}

char	*get_path_line(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i ++;
	return (envp[i]);
}

void	parse(t_pipex *pobj, char **envp, char **av)
{
	char	*pathline;
	int		i;

	pathline = get_path_line(envp);
	if (!pathline)
		error_terminate("ERROR: nopath", pobj);
	i = ft_strlen(pathline);
	pathline = ft_substr(pathline, 5, i);
	i = -1;
	pobj->paths = ft_split(pathline, ':');
	free(pathline);
	while (pobj->paths[++i])
		pobj->paths[i] = ft_joinloc(pobj->paths[i], ft_strdup("/"));
	pobj->infile = open(av[1], O_RDONLY);
	pobj->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pobj->command1 = ft_psplit(av[2], ' ', pobj);
	pobj->command2 = ft_psplit(av[3], ' ', pobj);
}
