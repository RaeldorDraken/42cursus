/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/09 13:06:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

size_t	ft_pstrnum(const char *s, char c)
{	
	size_t	len;
	size_t	numb;
	int		quotes;

	len = 0;
	numb = 0;
	quotes = 0;
	while (s[len])
	{
		if (s[len] == '\'' || s[len] == '\"')
			quotes ++;
		while (s[len] == c || s[len] == '\'' || s[len] == '\"')
		{
			if (s[len] == '\'' || s[len] == '\"')
				quotes ++;
			len++;
		}
		if (s[len] && (s[len] != c && quotes <= 0))
			numb++;
		while (s[len] != 0 && s[len] != c)
		{
			if (s[len] == '\'' || s[len] == '\"')
				quotes --;
			len++;
		}
	}
	return (numb);
}

char	*ft_pstrset(const char *s, char c)
{
	char	*sr;
	size_t	len;
	int		quotes;

	quotes = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	while (s[len] == '\'' || s[len] == '\"')
		quotes ++;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	len = 0;
	while ((s[len] != c || quotes > 0) && s[len])
	{
		if (s[len] == '\'' || s[len] == '\"')
			quotes --;
		else
			sr[len] = s[len];
		len++;
	}
	sr[len] = '\0';
	return (sr);
}

char	**ft_psplit(const char *s, char c)
{
	char	**strings;
	size_t	n;
	size_t	strn;

	n = 0;
	strn = ft_pstrnum(s, c);
	strings = ft_calloc(sizeof(char **), strn + 1);
	if (!strings)
		return (0);
	while (n < strn)
	{
		while (*s == c)
			s++;
		strings[n] = ft_pstrset(s, c);
		if (!strings[n])
		{
			while (n > 0)
				free(strings[--n]);
			free(strings);
			return (0);
		}
		s += ft_strlen(strings[n++]);
	}
	strings[n] = 0;
	return (strings);
}
