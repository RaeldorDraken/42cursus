/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/02/21 10:56:38 by eros-gir         ###   ########.fr       */
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
//	if (vars->prompt != NULL)
//		free (vars->prompt);
	vars->prompt = ft_calloc(ft_strlen(input) + 1, 1);
	vars->inputline = NULL;
	ft_strlcpy(vars->prompt, input, ft_strlen(input));
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
		if (vars.inputline == NULL)
			vars.inputline = readline(vars.prompt);
		else
			vars.inputlen = ft_strlen(vars.inputline);
		if (vars.inputlen <= 0)
			looping = 1;
	}
//	if (feof(stdin))
//		exit (0);
}