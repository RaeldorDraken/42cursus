/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/03/18 16:19:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

//Global variable
void	(*msh_sigint_handler)(int i);

void	msh_ignore_signals(t_vars *vars)
{
	vars->sigbool = 1;
	msh_sigint_handler = signal(SIGINT, SIG_IGN);
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
	char	*exitcomm;
	int		i;

	exitcomm = "exit";
	i = 0;
	if (!ft_strncmp(vars->inputline, exitcomm,
			msh_maxvalue(vars->inputlen, ft_strlen(exitcomm))))
		return (0);
	else
	{
		if (vars->inputline[0] != '\0')
		{
			vars->inputcomm = msh_split(' ', vars, 0, 0);
			while (vars->inputcomm[i] != NULL)
			{
				printf("%d: %s\n", i, vars->inputcomm[i]);
				if (vars->inputcomm[i] != NULL)
					free (vars->inputcomm[i++]);
			}
		}
		else if (vars->inputcomm != NULL)
		{
			free (vars->inputcomm);
			vars->inputcomm = NULL;
		}
	}
	return (1);
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
		}
		else
			break ;
		looping = msh_getting_commands(&vars);
	}
	msh_clear_memory(&vars);
}
