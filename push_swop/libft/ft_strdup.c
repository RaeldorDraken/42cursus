/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:26:37 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:46:45 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	void	*s2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
	{
		errno = ENOMEM;
		return (s2);
	}
	s2 = ft_memcpy(s2, s1, ft_strlen(s1) + 1);
	return ((char *)s2);
}
