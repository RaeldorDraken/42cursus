/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/19 13:01:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strnum(char const *s, char c)
{	
	size_t	len;
	size_t	numb;

	len = 0;
	while (s[len])
	{
		if (len == 0 || (s[len - 1] == c && s[len] != c))
			numb++;
		len++;
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char		**strings;
	size_t		l;
	long int	n;
	size_t		strn;
	size_t		strl;

	l = 0;
	n = -1;
	strn = ft_strnum(s, c);
	strings = ft_calloc(sizeof(char *), strn + 1);
	while (++n < (long int)strn && strings)
	{
		strl = 0;
		while (s[l] == c)
			l++;
		while (s[l] != c)
			strl++;
		strings[n] = ft_calloc(sizeof(**strings), strl + 1);
		ft_strlcpy(strings[n], &s[l], strl);
		strings[n][strl] = '\0';
		while (s[l] != c)
			l++;
	}
	strings[n] = 0;
	return (strings);
}
