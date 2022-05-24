/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:50:56 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/24 12:24:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	child_process(t_pipex *pobj)
{
	if (dup2(pobj->infile, STDIN_FILENO) < 0)
	{
		close(pobj->infile);
		exit(0);
	}
	dup2(pobj->end[1], STDOUT_FILENO);
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

void	pipex(t_pipex *pobj, char **envp)
{
	pid_t	parent;

	pipe(pobj->end);
	parent = fork();
	if (parent < 0)
		return (perror("Fork: "));
	if (!parent)
		child_process(pobj);
	else
		parent_process(pobj);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pobj;

	if (ac != 5)
		argerror(ac);
	pobj.infile = open(av[1], O_RDONLY);
	pobj.outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	pobj.command1 = ft_split(av[2], ' ');
	pobj.command2 = ft_split(av[3], ' ');
	if (pobj.infile < 0 || pobj.outfile < 0)
		return (-1);
	pipex(&pobj, envp);
	return (0);
}
