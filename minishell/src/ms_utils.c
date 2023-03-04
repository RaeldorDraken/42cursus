/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:06:58 by eros-gir          #+#    #+#             */
/*   Updated: 2023/03/04 11:49:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/mslib.h"

void	msh_set_lex(size_t *len, size_t *num, int *quotes)
{
	*len = 0;
	*num = 0;
	*quotes = 0;
}

size_t	add_numb(int quotes)
{
	if (quotes <= 0)
		return (1);
	return (0);
}

int	msh_check_quotes(char c)
{
	if (c == '\'')
		return (1);
	else if (c == '\"')
		return (2);
	else if (c == '.')
		return (3);
	return (0);
}

size_t	msh_strnum(const char *s, char c)
{	
	size_t	len;
	size_t	numb;
	int		quotes;

	msh_set_lex(&len, &numb, &quotes);
	while (s[len])
	{
		while (s[len] == c || ((s[len] == '\'' || s[len] == '\"')
				&& s[len - 1] != '\\'))
		{
			if ((s[len] == '\'' || s[len] == '\"') && s[len - 1] != '\\')
				numb += add_numb(quotes++);
			len++;
		}
		if (s[len] && (s[len] != c && quotes <= 0))
			numb++;
		while (s[len] != 0 && s[len] != c)
		{
			if ((s[len] == '\'' || s[len] == '\"') && s[len - 1] != '\\')
				quotes --;
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
