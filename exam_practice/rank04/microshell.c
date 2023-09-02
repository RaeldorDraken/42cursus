/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:50:45 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/02 19:30:39 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int	print_err(char *str, char *arg)
{
	while (*str)
		write(2, str++, 1);
	if (arg)
	{
		while (*arg)
			write(2, arg++, 1);
	}
	write(2, "\n", 1);
	return (1);
}

int	execution(char **argv, int i, int old_fd, char **envp)
{
	argv[i] = NULL;
	dup2(old_fd, STDIN_FILENO);
	close(old_fd);
	execve(argv[0], argv, envp);
	return (print_err("error: cannot execute ", argv[0]));
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	pipe_fd[2];
	int	old_fd;

	i = 0;
	old_fd = dup(STDIN_FILENO);
	if (argc <= 1)
		return (0);
	while (argv[i] && argv[i + 1])
	{
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") && strcmp(argv[i], "|"))
			i++;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (i != 2)
				return (print_err("error: cd: bad arguments", NULL));
			else if (chdir(argv[1]) != 0)
				return (print_err("error: cd: cannot change directory to ", argv[i]));
		}
		else if (i != 0 && (argv[i] == NULL || strcmp(argv[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (execution(argv, i, old_fd, envp))
					return (1);
			}
			else
			{
				close(old_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				old_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(argv[i], "|") == 0)
		{
			pipe(pipe_fd);
			if (fork() == 0)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				if (execution(argv, i, old_fd, envp))
					return (1);
			}
			else
			{
				close(pipe_fd[1]);
				close(old_fd);
				old_fd = pipe_fd[0];
			}
		}
	}
	close(old_fd);
	return (0);
}