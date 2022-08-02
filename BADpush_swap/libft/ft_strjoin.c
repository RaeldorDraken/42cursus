/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:00:32 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 11:53:01 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new_str == NULL)
		errno = ENOMEM;
	else
	{
		(void)ft_memcpy(new_str, s1, ft_strlen(s1));
		(void)ft_memcpy(new_str + ft_strlen(s1), s2, ft_strlen(s2));
		(void)ft_memset(new_str + ft_strlen(s1) + ft_strlen(s2), 0, 1);
	}
	return ((char *)new_str);
}
