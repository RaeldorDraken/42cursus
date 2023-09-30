/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:50:45 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/30 20:15:10 by eros-gir         ###   ########.fr       */
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
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	return (1);
}

int	execution(char *av[], int i, int old_fd, char *env[])
{
	av[i] = NULL;
	dup2(old_fd, 0);
	close(old_fd);
	execve(av[0], av, env);
	return (print_err("error: cannot execute ", av[0]));
}

int	main(int ac, char *av[], char *env[])
{
	int	i;
	int	pipe_fd[2];
	int	old_fd;

	(void)ac;
	i = 0;
	old_fd = dup(0);
	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				print_err("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				print_err("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				if (execution(av, i, old_fd, env))
					return (1);
			}
			else
			{
				close(old_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				old_fd = dup(0);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			pipe(pipe_fd);
			if (fork() == 0)
			{
				dup2(pipe_fd[1], 1);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				if (execution(av, i, old_fd, env))
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