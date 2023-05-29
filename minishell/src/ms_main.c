/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/29 10:56:34 by eros-gir         ###   ########.fr       */
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

void	msh_ignore_signals(t_vars *vars, int ac, char **av)
{
	if (ac > 1 || av[1] != NULL)
	{
		printf("ERROR: the program does not take any arguments!");
		exit(1);
	}
	vars->sigbool = 1;
	signal(SIGINT, msh_sigint_handler);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	msh_set_vars(t_vars *vars, char *input, char **envp)
{
	vars->prompt = ft_calloc(ft_strlen(input) + 1, 1);
	vars->inpli = NULL;
	vars->envar = envp;
	ft_strlcpy(vars->prompt, input, ft_strlen(input));
	msh_acptd_comm(vars);
}

void	msh_clear_memory(t_vars *vars)
{
	free (vars->prompt);
	if (vars->inpli != NULL)
		free (vars->inpli);
	if (vars->btins != NULL)
		free (vars->btins);
	if (vars->tokens != NULL)
		free (vars->tokens);
	exit(0);
}

//printf("%s: %d\n", vars.inpli, vars.inplen); //debug line
int	main(int ac, char **av, char **envp)
{
	t_vars	vars;
	int		looping;

	looping = 1;
	msh_ignore_signals(&vars, ac, av);
	msh_set_vars(&vars, "msh %  ", envp);
	while (looping)
	{
		looping = 0;
		vars.inpli = readline(vars.prompt);
		if (vars.inpli != NULL)
		{
			if (vars.inpli[0] == '\0')
			{
				free(vars.inpli);
			}
			vars.inplen = ft_strlen(vars.inpli);
			add_history(vars.inpli);
		}
		else
			break ;
		looping = msh_getting_commands(&vars, envp);
		msh_free_commands(&vars);
	}
	msh_clear_memory(&vars);
}
