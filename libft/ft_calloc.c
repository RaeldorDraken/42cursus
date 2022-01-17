/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:59:59 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/17 19:15:27 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		len;
	size_t		fsize;
	void		*result;
	char		*setzero;

	fsize = (long int)(nmemb * size);
	if (fsize == 0)
	{
		return (0);
	}
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	setzero = (char *)result;
	if (fsize != 0)
	{
		len = -1;
		while (++len < fsize)
			setzero[len] = 0;
	}
	return (result);
}
