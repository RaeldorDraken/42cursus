/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:59:59 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/17 19:15:27 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*sr;
	size_t	len;
	size_t	l;

	l = 0;
	len = (size_t)ft_strlen(s);
	sr = ft_calloc(sizeof(char), len);
	if (!sr)
		return (0);
	while (s[l])
	{
		sr[l] = s[l];
		l++;
	}
	return (sr);
}
