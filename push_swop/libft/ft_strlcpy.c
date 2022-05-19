/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:00:16 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:29:07 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	if (ft_strlen(src) + 1 < dstsize)
		dst = ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (dstsize != 0)
	{
		dst = ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (ft_strlen(src));
}
