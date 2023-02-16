/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:05:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/02/16 12:12:33 by eros-gir         ###   ########.fr       */
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

void	set_prompt(t_vars *vars, char *input)
{
//	if (vars->prompt != NULL)
//		free (vars->prompt);
	vars->prompt = ft_calloc(ft_strlen(input) + 1, 1);
	ft_strlcpy(vars->prompt, input, ft_strlen(input));
}

int	main(void)
{
	t_vars	vars;

	ignore_signals();
	set_prompt(&vars, "raeldor %");

	while (1);
}