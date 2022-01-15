/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:03:55 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/15 13:18:58 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
	return (0);
}
