/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:18:02 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:18:26 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_cat;

	len_cat = ft_strlen(dst) + ft_strlen(src) + 1;
	if (ft_strlen(dst) + 1 > dstsize)
		return (ft_strlen(src) + dstsize);
	if (len_cat > dstsize)
		ft_strlcpy(dst + ft_strlen(dst), src, dstsize - ft_strlen(dst));
	else
	{
		ft_strlcpy(dst + ft_strlen(dst), src, ft_strlen(src) + 1);
		dst[len_cat - 1] = '\0';
	}
	return (len_cat - 1);
}
