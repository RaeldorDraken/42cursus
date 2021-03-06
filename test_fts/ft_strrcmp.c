/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:42:17 by eros-gir          #+#    #+#             */
/*   Updated: 2022/06/29 10:44:59 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

size_t	ft_strlen(const char *s);

int	ft_strrcmp(const char *str1, const char *str2, size_t n)
{
	size_t			l[4];
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	l[0] = ft_strlen((const char *)s1);
	l[1] = ft_strlen((const char *)s2);
	l[2] = l[0];
	l[3] = l[1];
	if (n == 0)
		return (0);
	while (s1[l[0]] == s2[l[1]] && l[0] > l[2] - n && l[1] > l[3] - n
		&& l[0] > 0 && l[1] > 0)
	{
		l[0]--;
		l[1]--;
	}
	return (s1[l[0]] - s2[l[1]]);
}

int	main(void)
{
	char *s = ".sh";
	char *r = "wc";
	printf("%s <-> %s : %d", s, r, ft_strrcmp(s, r, 3));
	return (0);
}
