/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/14 12:27:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipexlib.h"

void	set_vars(size_t *len, size_t *num, int *quotes)
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

size_t	ft_pstrnum(const char *s, char c)
{	
	size_t	len;
	size_t	numb;
	int		quotes;

	set_vars(&len, &numb, &quotes);
	while (s[len])
	{
		while (s[len] == c || s[len] == '\'' || s[len] == '\"')
		{
			if (s[len] == '\'' || s[len] == '\"')
				numb += add_numb(quotes);
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

char	*ft_pstrset2(const char *s, char c)
{
	char	*sr;
	size_t	len;

	len = 0;
	ft_putendl_fd((char*)s, 2);
	while (s[len] != c && s[len - 1] != '\\' && s[len])
		len++;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	len = 0;
	while (s[len])
	{
		if (s[len] == c && ((s[len - 1] != '\\' && s[len - 1] != ' ')))
			break ;
		sr[len] = s[len];
		len++;
	}
	sr[len] = '\0';
	ft_putendl_fd((char*)sr, 2);
	return (sr);
}

char	*ft_pstrset(const char *s, char c)
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

char	*ft_pgetset(const char *s, char c, int qt)
{
	if (qt == 1)
		return (ft_pstrset2(s, '\''));
	else if (qt == 2)
		return (ft_pstrset2(s, '\"'));
	else
		return (ft_pstrset(s, c));
}

char	**ft_psplit(const char *s, char c)
{
	char	**strings;
	size_t	n;
	size_t	strn;
	int		quotes;

	n = 0;
	quotes = 0;
	strn = ft_pstrnum(s, c);
	strings = ft_calloc(sizeof(char **), strn + 1);
	if (!strings)
		return (0);
	while (n < strn)
	{
		ft_putendl_fd((char*)s, 2);
		while (*s == c || *s == '\'' || *s == '\"')
		{
			if (*s == '\'')
				quotes = 1;
			else if (*s == '\"')
				quotes = 2;
			s++;
		}
		strings[n] = ft_pgetset(s, c, quotes);
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
