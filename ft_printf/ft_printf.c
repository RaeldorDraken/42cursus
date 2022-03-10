/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:43:08 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/10 17:59:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *string, ...)
{
	size_t	lenght;

	lenght = 0;
	if (!string)
		return (0);
	else
		lenght = ft_strlen(string);
	ft_putstr((char *) string);
	return (lenght);
}
