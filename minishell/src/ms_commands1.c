/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_commands1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:55:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/15 12:18:41 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

void	msh_acptd_comm(t_vars *vars)
{
	vars->btins = ft_calloc(sizeof(char *), 8);
	vars->tokens = ft_calloc(sizeof(char *), 7);
	vars->btins[0] = "echo";
	vars->btins[1] = "cd";
	vars->btins[2] = "pwd";
	vars->btins[3] = "export";
	vars->btins[4] = "unset";
	vars->btins[5] = "env";
	vars->btins[6] = "exit";
	vars->btins[7] = NULL;
	vars->tokens[0] = "|";
	vars->tokens[1] = "$";
	vars->tokens[2] = "<";
	vars->tokens[3] = ">";
	vars->tokens[4] = "<<";
	vars->tokens[5] = ">>";
	vars->tokens[6] = NULL;
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

void	msh_getting_commands3(t_vars *vars, int maxval)
{
	char	*tmp;

	if (!ft_strncmp(vars->inpcomm[0], vars->btins[0], maxval))
	{
		tmp = msh_echo(vars);
		printf("%s", tmp);
		free (tmp);
	}
}

int	msh_getting_commands2(t_vars *vars, int i)
{
	int		maxval;

	maxval = ft_strlen(vars->inpcomm[0]);
	while (vars->btins[++i] != NULL)
	{
		if (!ft_strncmp(vars->inpcomm[0], vars->btins[i], maxval))
			break ;
	}
	if (vars->btins[i] == NULL)
	{
		printf("%s: command not found: %s\n", vars->prompt, vars->inpcomm[0]);
		return (1);
	}
	msh_getting_commands3(vars, maxval);
	if (!ft_strncmp(vars->inpcomm[0], vars->btins[5], maxval))
	{
		i = -1;
		while (vars->envar[++i] != NULL)
			printf("%s\n", vars->envar[i]);
	}
	if (!ft_strncmp(vars->inpcomm[0], vars->btins[6], maxval))
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
	if (!msh_getting_commands2(vars, -1))
		return (0);
	return (1);
}
