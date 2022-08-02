/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:00:21 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:57:13 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	char			*str;

	if (s1 == NULL || set == NULL )
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (ft_calloc(1, 1));
	while (s1[start] != '\0')
	{
		if (ft_memchr(set, s1[start], ft_strlen(set)) == NULL)
			break ;
		start++;
	}
	while (len > 0)
	{
		if (ft_memchr(set, s1[len - 1], ft_strlen(set)) == NULL)
			break ;
		len--;
	}
	str = ft_substr(s1, start, len - start);
	return (str);
}
