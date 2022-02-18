/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:41 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/18 18:42:59 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"

struct	s_line {
	char			*string;
	struct s_line	*next;
};

char	*ft_strdup(char *s)
{
	char	*sr;
	size_t	len;
	size_t	l;

	l = 0;
	len = (size_t)ft_strlen(s);
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	while (s[l])
	{
		sr[l] = s[l];
		l++;
	}
	sr[l] = '\0';
	return (sr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	lo;
	size_t	lr;
	size_t	maxlo;
	char	*sr;

	lo = start;
	maxlo = ft_strlen(s);
	lr = 0;
	if (!s || maxlo <= lo)
		return (ft_strdup(""));
	if (len >= maxlo)
		len = maxlo;
	sr = ft_calloc(sizeof(char), len + 1);
	if (!sr)
		return (0);
	while (lr < len && lo < maxlo)
		sr[lr++] = s[lo++];
	sr[lr] = '\0';
	return (sr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	len;
	char	*str;

	str = (char *)s;
	if (n != 0)
	{
		len = -1;
		while (++len < n)
			str[len] = 0;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	fsize;
	void	*result;

	fsize = nmemb * size;
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, fsize);
	return (result);
}

size_t	ft_strlen(char *s)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*sr;

	l1 = 0;
	l2 = 0;
	if (!s1)
	{
		s1 = ft_calloc(sizeof (char), 2);
		s1[0] = '\0';
	}
	sr = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sr)
		return (0);
	while (s1[l1])
	{
		sr[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
	{
		sr[l1 + l2] = s2[l2];
		l2++;
	}
	sr[l1 + l2] = '\0';
	free(s1);
	return (sr);
}
