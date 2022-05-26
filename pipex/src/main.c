/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:50:56 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/26 12:25:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	child_process(t_pipex *pobj, char **av, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(pobj->infile, STDIN_FILENO) < 0)
	{
		close(pobj->infile);
		exit(0);
	}
	dup2(pobj->end[1], STDOUT_FILENO);
	while (pobj->paths[++i])
	{
		cmd = ft_strjoin(pobj->paths[i], av[2]);
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
		exit(0);
	}
	dup2(pobj->end[0], STDIN_FILENO);
	close(pobj->end[1]);
	close(pobj->outfile);
}

void	pipex(t_pipex *pobj, char **av, char **envp)
{
	pid_t	parent;

	pipe(pobj->end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(pobj, av, envp);
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
		ft_putendl_fd(pobj.paths[i++], 1);
	i = 0;
	while (pobj.command1[i])
		ft_putendl_fd(pobj.command1[i++], 1);
	i = 0;
	while (pobj.command2[i])
		ft_putendl_fd(pobj.command2[i++], 1);
	if (pobj.infile < 0 || pobj.outfile < 0)
		exit(0);
	pipex(&pobj, av, envp);
	return (0);
}
