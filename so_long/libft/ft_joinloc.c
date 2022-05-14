/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:08:45 by eros-gir          #+#    #+#             */
/*   Updated: 2022/05/14 18:24:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	free2str(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

char	*ft_joinloc(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*sr;

	l1 = -1;
	l2 = -1;
	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 2);
		s1[0] = '\0';
	}
	sr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!sr)
	{
		free2str(s1, s2);
		return (0);
	}
	while (s1[++l1])
		sr[l1] = s1[l1];
	while (s2[++l2])
		sr[l1 + l2] = s2[l2];
	sr[l1 + l2] = '\0';
//	free2str(s1, s2);
	return (sr);
}
