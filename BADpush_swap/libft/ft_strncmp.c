/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:30:28 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:08:51 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	last;
	int		r;

	i = 0;
	r = 0;
	if (ft_strlen(s1) > ft_strlen(s2))
		last = ft_strlen(s1);
	else
		last = ft_strlen(s2);
	while (i < last && i < n)
	{
		r += (unsigned char)s1[i] - (unsigned char)s2[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (r);
}
