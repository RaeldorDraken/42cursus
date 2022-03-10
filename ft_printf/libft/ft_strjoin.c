/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:08:45 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:26 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
