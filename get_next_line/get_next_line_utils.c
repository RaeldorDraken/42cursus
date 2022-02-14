/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:03:41 by eros-gir          #+#    #+#             */
/*   Updated: 2022/02/14 17:20:10 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include"get_next_line.h"

struct	s_line {
	char			*string;
	struct s_line	*next;
};

void	ft_bzero(void *s, size_t n)
{
	size_t	len;
	char	*str;

	str = (char *)s;
	if (n != 0)
	{
		len = -1;
		while (++len < n)
			str[len] = 0;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	fsize;
	void	*result;

	fsize = nmemb * size;
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, fsize);
	return (result);
}
