/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:41 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/16 19:09:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"

struct	s_line {
	char			*string;
	struct s_line	*next;
};

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

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	int	l;

	l = 0;
	while (c > 127)
		c = c - 256;
	while (c < 0)
		c = c + 256;
	while (s[l] && s[l] != c)
		l++;
	if (s[l] == c)
		return ((char *)(s + l));
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	len;
	char	*sr;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	len = 0;
	sr = ft_calloc(sizeof(char), l1 + l2 + 1);
	if (!sr)
		return (0);
	while (s1[len])
	{
		sr[len] = s1[len];
		len++;
	}
	len = 0;
	while (s2[len])
	{
		sr[l1 + len] = s2[len];
		len++;
	}
	sr[l1 + len] = '\0';
	return (sr);
}
