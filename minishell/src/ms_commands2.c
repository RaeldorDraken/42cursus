/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_commands2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:33:12 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/15 12:17:24 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

int	msh_echo_init(t_vars *vars, int i, int *flag)
{
	while (vars->inpcomm[i][0] == '-')
	{
		if (vars->inpcomm[i][1] == 'n')
			*flag = 1;
		i++;
	}
	return (i);
}

char	*msh_echo(t_vars *vars)
{
	char	*echor;
	int		i;
	int		j;
	int		flag;

	i = 1;
	flag = 0;
	echor = ft_strdup("");
	while (vars->inpcomm[i])
	{
		i = msh_echo_init(vars, i, &flag);
		j = 0;
		while (j != -1 && vars->tokens[j])
		{
			if (!ft_strncmp(vars->inpcomm[i], vars->tokens[j],
					ft_strlen(vars->tokens[j])))
				j = -1;
			else
				j ++;
		}
		if (j == -1)
			break ;
		echor = ft_joinloc(echor, ft_strdup(vars->inpcomm[i]));
		echor = ft_joinloc(echor, ft_strdup(" "));
		i++;
	}
	if (flag == 0)
		echor = ft_joinloc(echor, ft_strdup("\n"));
	return (echor);
}
