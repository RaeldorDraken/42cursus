/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:55:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/03 12:02:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

void	msh_getting_commands2(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->inputline[0] != '\0')
	{
		vars->inputcomm = msh_split(' ', vars, 0, 0);
		if (vars->inputline != NULL)
			free (vars->inputline);
		while (vars->inputcomm[i] != NULL)
		{
			printf("%d: %s\n", i, vars->inputcomm[i]);
			if (vars->inputcomm[i] != NULL)
				free (vars->inputcomm[i++]);
		}
	}
	if (vars->inputcomm != NULL)
	{
		free (vars->inputcomm);
		vars->inputcomm = NULL;
	}
}

int	msh_getting_commands(t_vars *vars)
{
	char	*exitcomm;

	exitcomm = "exit";
	if (!ft_strncmp(vars->inputline, exitcomm,
			msh_maxvalue(vars->inputlen, ft_strlen(exitcomm))))
		return (0);
	else
	{
		msh_getting_commands2(vars);
	}
	return (1);
}
