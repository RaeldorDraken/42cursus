/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raeldor <raeldor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/02/23 11:07:39 by raeldor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

//Global variable

void	msh_ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	msh_set_vars(t_vars *vars, char *input)
{
	vars->prompt = ft_calloc(ft_strlen(input) + 1, 1);
	vars->inputline = NULL;
	ft_strlcpy(vars->prompt, input, ft_strlen(input));
}

void	msh_clear_memory(t_vars *vars)
{
	free (vars->prompt);
	if (vars->inputline != NULL)
		free (vars->inputline);
}

int	msh_getting_commands(t_vars *vars)
{
	char *exitcomm;

	exitcomm = "quit";
	if (ft_strncmp(vars->inputline, exitcomm, 4))
	{
		printf("%s: %d\n", vars->inputline, vars->inputlen); //debug line
		printf("%s: %ld\n", exitcomm, ft_strlen(exitcomm)); //debug line
		return (0);
	}
	return (1);
}

int	main(void)
{
	t_vars	vars;
	int		looping;

	looping = 1;
	msh_ignore_signals();
	msh_set_vars(&vars, "raeldor %%");
	while (looping)
	{
		looping = 0;
		printf("%s: %d\n", vars.inputline, vars.inputlen); //debug line
		vars.inputline = readline(vars.prompt);
		if (vars.inputline != NULL)
			vars.inputlen = ft_strlen(vars.inputline);
		if (msh_getting_commands(&vars))
			looping = 1;
	}
	msh_clear_memory(&vars);
}