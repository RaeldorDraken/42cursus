/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/18 13:01:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	sl;
	size_t	ss;
	size_t	len;
	char	*sr;

	len = 0;
	sl = ft_strlen(s1);
	sr = ft_calloc(sizeof(char), sl + 1);
	if (!sr)
		return (0);
	sl = 0;
	while (s1[sl])
	{
		ss = 0;
		while (set[ss++])
			sl++;
		sr[len++] = s1[sl++];
	}
	sr[len] = '\0';
	return (sr);
}
