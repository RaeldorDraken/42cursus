/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:06:58 by eros-gir          #+#    #+#             */
/*   Updated: 2023/03/29 12:15:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

void	msh_count_quotes(t_vars *vars)
{
	int	len;

	len = -1;
	while (vars->inputline[++len])
	{
		if (vars->inputline[len] == '\'')
			vars->s_quotes ++;
		else if (vars->inputline[len] == '\"')
			vars->d_quotes ++;
	}
}

int	msh_check_quotes(t_vars *vars, char c)
{
	if (c == '\'')
	{
		if (vars->s_quotes % 2 == 0)
			return (1);
		else
			return (0);
	}
	else if (c == '\"')
	{
		if (vars->s_quotes % 2 == 0)
			return (2);
		else
			return (0);
	}
	else if (c == '.')
		return (3);
	return (0);
}

size_t	msh_strnum(const char *s, char c)
{	
	size_t	len;
	size_t	numb;

	len = 0;
	numb = 0;
	while (s[len])
	{
		while (s[len] && s[len] == c)
			len++;
		numb++;
		while (s[len] && s[len] != c)
		{
			if ((s[len] == '\'' || s[len] == '\"'))
				numb++;
			len++;
		}
	}
	return (numb);
}

size_t	msh_maxvalue(size_t first, size_t second)
{
	if (first > second)
		return (first);
	else
		return (second);
}
