/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:42:17 by eros-gir          #+#    #+#             */
/*   Updated: 2022/01/13 12:01:02 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (0);
	while (str1[l] == str2[l] && l < n - 1 && str1[l])
		l++;
	return (str1[l] - str2[l]);
}
