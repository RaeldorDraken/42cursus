/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:07:00 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:12:57 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c_;

	str = (unsigned char *)s;
	c_ = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[0] == c_)
			return (str);
		str++;
		i++;
	}	
	return (NULL);
}
