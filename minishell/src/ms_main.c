/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/02/21 11:12:55 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

//Global variable


void	ignore_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_vars(t_vars *vars, char *input)
{
	vars->prompt = ft_calloc(ft_strlen(input) + 1, 1);
	vars->inputline = NULL;
	ft_strlcpy(vars->prompt, input, ft_strlen(input));
}

void	clear_memory(t_vars *vars)
{
	free (vars->prompt);
	if (vars->inputline != NULL)
		free (vars->inputline);
}

int	main(void)
{
	t_vars	vars;
	int		looping;

	looping = 1;
	ignore_signals();
	set_vars(&vars, "raeldor %%");
	while (looping)
	{
		looping = 0;
		vars.inputline = readline(vars.prompt);
		if (vars.inputline != NULL)
			vars.inputlen = ft_strlen(vars.inputline);
		if (vars.inputlen <= 0)
			looping = 1;
	}
	clear_memory(&vars);
}