/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:30:41 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:45:50 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = malloc(size * count);
	if (p == NULL)
	{
		errno = ENOENT;
		return (p);
	}
	p = p + (size * count) - 1;
	i = (size * count) - 1;
	while (i >= 0)
	{
		*p = 0;
		p--;
		i--;
	}
	p++;
	return ((void *)p);
}
