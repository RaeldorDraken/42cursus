/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:02:11 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/01/26 12:11:56 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		str = ft_itoa(n);
		ft_putstr_fd(str, fd);
		free(str);
	}
}
