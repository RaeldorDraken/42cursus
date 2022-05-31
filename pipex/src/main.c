/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:50:56 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/31 13:03:43 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	child_process(t_pipex *pobj, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(pobj->infile, STDIN_FILENO) < 0)
	{
		close(pobj->infile);
		exit(EXIT_FAILURE);
	}
	dup2(pobj->end[1], STDOUT_FILENO);
	while (pobj->paths[++i])
	{
		cmd = ft_strjoin(pobj->paths[i], pobj->command1[0]);
		execve(cmd, pobj->command1, envp);
		perror("exeve ERROR");
		free(cmd);
	}
	close(pobj->end[0]);
	close(pobj->infile);
}

void	parent_process(t_pipex *pobj)
{
	int	status;

	waitpid(-1, &status, 0);
	if (dup2(pobj->outfile, STDOUT_FILENO) < 0)
	{
		close(pobj->outfile);
		exit(EXIT_FAILURE);
	}
	dup2(pobj->end[0], STDIN_FILENO);
	close(pobj->end[1]);
	close(pobj->outfile);
}

void	pipex(t_pipex *pobj, char **envp)
{
	pid_t	parent;

	pipe(pobj->end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(pobj, envp);
	else
		parent_process(pobj);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pobj;
	int		i;

	i = 0;
	if (ac != 5)
		argerror(ac);
	parse(&pobj, envp, av);
	while (pobj.paths[i])
		ft_putendl_fd(ft_strjoin(pobj.paths[i++], pobj.command1[0]), 1);
	i = 0;
	while (pobj.command1[i])
		ft_putendl_fd(pobj.command1[i++], 1);
	i = 0;
	while (pobj.command2[i])
		ft_putendl_fd(pobj.command2[i++], 1);
	if (pobj.infile < 0 || pobj.outfile < 0)
		exit(EXIT_FAILURE);
	pipex(&pobj, envp);
	return (0);
}
