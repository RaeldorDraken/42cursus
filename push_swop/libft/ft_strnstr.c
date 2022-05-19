/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:40:20 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:26:54 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	end;
	size_t	i;
	size_t	needle_size;

	end = ft_strlen(haystack);
	needle_size = ft_strlen(needle);
	if ((int)len <= -1)
		len = end;
	if (needle_size == 0)
		return ((char *)haystack);
	if (end > len)
		end = len;
	i = 0;
	while (ft_strlen(needle) <= len - i)
	{
		if (!ft_strncmp(&haystack[i], needle, (ft_strlen(needle))))
			return ((char *) &haystack[i]);
		else
			i++;
	}
	return (NULL);
}
