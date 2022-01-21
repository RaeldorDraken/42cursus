/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/20 12:58:05 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strnum(const char *s, char c)
{	
	size_t	len;
	size_t	numb;

	len = 0;
	numb = 0;
	while (s[len])
	{
		if ((s[len - 1] == c && s[len] != c))
			numb++;
		len++;
	}
	if (!ft_strchr(s, c))
		numb++;
	return (numb);
}

size_t	ft_substrlen(const char *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start + len] != c && s[start + len])
		len++;
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char	**strings;
	size_t	l;
	size_t	n;
	size_t	strn;
	size_t	strl;

	l = 0;
	n = 0;
	strn = ft_strnum(s, c);
	strings = ft_calloc(sizeof(char *), strn + 1);
	if (!strings)
		return (0);
	while (n < strn && s[l])
	{
		while (s[l] == c)
			l++;
		strl = ft_substrlen(s, l, c);
		strings[n] = ft_substr(s, l, strl + 1);
		strings[n++][strl] = 0;
		while (s[l] != c)
			l++;
	}
	strings[n] = 0;
	return (strings);
}
