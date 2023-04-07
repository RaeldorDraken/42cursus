/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/07 10:46:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

//Global variable

void	msh_sigint_handler(int sig)
{
	if (sig != 0)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	msh_ignore_signals(t_vars *vars)
{
	vars->sigbool = 1;
	signal(SIGINT, msh_sigint_handler);
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

//printf("%s: %d\n", vars.inputline, vars.inputlen); //debug line
int	main(void)
{
	t_vars	vars;
	int		looping;

	looping = 1;
	msh_ignore_signals(&vars);
	msh_set_vars(&vars, "msh %  ");
	while (looping)
	{
		looping = 0;
		vars.inputline = readline(vars.prompt);
		if (vars.inputline != NULL)
		{
			if (vars.inputline[0] == '\0')
			{
				free(vars.inputline);
			}
			vars.inputlen = ft_strlen(vars.inputline);
			add_history(vars.inputline);
		}
		else
			break ;
		looping = msh_getting_commands(&vars);
	}
	msh_clear_memory(&vars);
}
