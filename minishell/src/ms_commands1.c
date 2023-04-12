/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:55:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/12 13:04:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

void	msh_acptd_comm(t_vars *vars)
{
	int	i;

	i = 0;
	vars->accomm = ft_calloc(sizeof(char **), 8);
	vars->accomm[0] = "echo";
	vars->accomm[1] = "cd";
	vars->accomm[2] = "pwd";
	vars->accomm[3] = "export";
	vars->accomm[4] = "unset";
	vars->accomm[5] = "env";
	vars->accomm[6] = "exit";
	vars->accomm[7] = NULL;
	while (vars->accomm[i] != NULL)
	{
		printf("%d: %s\n", i, vars->accomm[i]);
		i ++;
	}
}

void	msh_free_commands(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->inpcomm[i] != NULL)
	{
		if (vars->inpcomm[i] != NULL)
			free (vars->inpcomm[i++]);
	}
	if (vars->inpcomm != NULL)
	{
		free (vars->inpcomm);
		vars->inpcomm = NULL;
	}
}

int	msh_getting_commands2(t_vars *vars)
{
	if (!ft_strncmp(vars->inpcomm[0], vars->accomm[6],
			ft_strlen(vars->accomm[6])))
		return (0);
	return (1);
}

int	msh_getting_commands(t_vars *vars)
{
	int	i;

	i = -1;
	if (vars->inpli[0] != '\0')
	{
		vars->inpcomm = msh_split(' ', vars, 0, 0);
		if (vars->inpli != NULL)
		{
			free (vars->inpli);
			vars->inpli = NULL;
		}
		while (vars->inpcomm[++i] != NULL)
			printf("%d: %s\n", i, vars->inpcomm[i]);
	}
	if (!msh_getting_commands2(vars))
		return (0);
	return (1);
}
