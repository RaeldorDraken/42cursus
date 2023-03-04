/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:18:17 by eros-gir          #+#    #+#             */
/*   Updated: 2023/03/04 11:51:03 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/mslib.h"

char	*msh_script(const char *s)
{
	char	*sr;
	size_t	len;
	size_t	len2;

	len = ft_strlen(s);
	len2 = 0;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	len = 0;
	while (s[len])
	{
		if ((s[len] == '\'' || s[len] == '\"') && s[len - 1] == '\\')
			len2 --;
		else if (s[len] == '\'' || s[len] == '\"')
			len ++;
		sr[len2++] = s[len++];
	}
	sr[len2] = '\0';
	return (sr);
}

char	*msh_strset2(const char *s, char c)
{
	char	*sr;
	size_t	len;
	size_t	len2;

	len = 0;
	len2 = 0;
	while (s[len] != c && (s[len - 1] == '\\' && s[len] == c) && s[len++])
		len2++;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	len = 0;
	while (s[len])
	{
		if (s[len] == c && s[len - 1] != '\\')
			break ;
		else if (s[len] == c && s[len - 1] == '\\')
			len2 --;
		sr[len2++] = s[len++];
	}
	sr[len2] = '\0';
	return (sr);
}

char	*msh_strset(const char *s, char c)
{
	char	*sr;
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	len = 0;
	while (s[len] != c && s[len])
	{
		sr[len] = s[len];
		len++;
	}
	sr[len] = '\0';
	return (sr);
}

char	*msh_getquotes(const char *s, char c, int qt)
{
	if (qt == 1)
		return (msh_strset2(s, '\''));
	else if (qt == 2)
		return (msh_strset2(s, '\"'));
	else if (qt == 3)
		return (msh_script(s));
	return (msh_strset(s, c));
}

char	**msh_split(const char *s, char c, t_vars *vars, int quotes)
{
	char	**strings;
	size_t	n;
	size_t	strn;

	n = 0;
	strn = msh_strnum(s, c);
	strings = ft_calloc(sizeof(char **), strn + 1);
	if (!strings)
		return (0);
	while (n < strn)
	{
		quotes = msh_check_quotes(*s);
		if (quotes != 3)
		{
			while (*s == c || *s == '\'' || *s == '\"')
			{
				quotes = msh_check_quotes(*s);
				s++;
			}
		}
		strings[n] = msh_getquotes(s, c, quotes);
		s += ft_strlen(strings[n++]);
	}
	return (strings);
}
