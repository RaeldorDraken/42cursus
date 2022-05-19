/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:59:19 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:49:29 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	sub_str = malloc(len + 1);
	if (sub_str == NULL)
		errno = ENOMEM;
	else
	{
		sub_str = (char *)ft_memcpy(sub_str, &s[start], len);
		sub_str[len] = '\0';
	}
	return (sub_str);
}
