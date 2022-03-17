/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:28:38 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/17 12:25:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"ft_printf.h"

int	main(void)
{
	char	*str;

	str = "This is a test string with %% all %s and a %% double here.\n";
	while (*str != '\0')
	{
		str = sp_putstr(str);
		str ++;
	}
}
