/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:18:50 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:16:12 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	if (s1 == NULL && s2 == NULL)
		return (0);
	while (n-- > 0)
		*s1++ = *s2++;
	return (dst);
}
