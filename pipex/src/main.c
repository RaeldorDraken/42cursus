/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:50:56 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/02 12:36:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	close_fds(t_pipex *pobj)
{
	close(pobj->end[0]);
	close(pobj->infile);
	close(pobj->end[1]);
	close(pobj->outfile);
}

void	child1_process(t_pipex *pobj, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	dup2(pobj->infile, STDIN_FILENO);
	dup2(pobj->end[1], STDOUT_FILENO);
	while (pobj->paths[++i])
	{
		cmd = ft_strjoin(pobj->paths[i], pobj->command1[0]);
		if (!access(cmd, F_OK))
		{
			close(pobj->end[0]);
			execve(cmd, pobj->command1, envp);
			perror("child2_exeve ERROR");
		}
		free(cmd);
	}
	close_fds(pobj);
}

void	child2_process(t_pipex *pobj, char **envp)
{
	int		i;
	char	*cmd;

	i = -1;
	dup2(pobj->outfile, STDOUT_FILENO);
	dup2(pobj->end[0], STDIN_FILENO);
	while (pobj->paths[++i])
	{
		cmd = ft_strjoin(pobj->paths[i], pobj->command2[0]);
		if (!access(cmd, F_OK))
		{
			close(pobj->end[1]);
			execve(cmd, pobj->command2, envp);
			perror("child2_exeve ERROR");
		}
		free(cmd);
	}
	close_fds(pobj);
}

void	pipex(t_pipex *pobj, char **envp)
{
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(pobj->end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child1_process(pobj, envp);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child2_process(pobj, envp);
	close(pobj->end[0]);
	close(pobj->end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pobj;

	if (ac != 5)
		argerror(ac);
	parse(&pobj, envp, av);
	if (pobj.infile < 0 || pobj.outfile < 0)
		exit(EXIT_FAILURE);
	pipex(&pobj, envp);
	return (0);
}
