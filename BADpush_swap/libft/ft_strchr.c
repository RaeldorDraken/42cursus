/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:15:51 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:22:31 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*sc;

	sc = (char *)s;
	c = c % 256;
	while (1)
	{
		if (sc[0] == c)
			return (sc);
		if (sc[0] == '\0')
			return (NULL);
		sc++;
	}
}
