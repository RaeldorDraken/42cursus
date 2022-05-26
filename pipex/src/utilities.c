/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:51:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/26 12:01:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

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
	i = ft_strlen(pathline);
	pathline = ft_substr(pathline, 5, i);
	i = -1;
	pobj->paths = ft_split(pathline, ':');
	free(pathline);
	while (pobj->paths[++i])
		pobj->paths[i] = ft_joinloc(pobj->paths[i], ft_strdup("/"));
	pobj->infile = open(av[1], O_RDONLY);
	pobj->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pobj->command1 = ft_split(av[2], ' ');
	pobj->command2 = ft_split(av[3], ' ');
}
