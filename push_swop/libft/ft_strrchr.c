/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:15:51 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:04:56 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*sc;

	sc = (char *) s;
	c = c % 256;
	i = ft_strlen(sc);
	while (i >= 0)
	{
		if (sc[i] == c)
			return (&sc[i]);
		i--;
	}
	return (NULL);
}
