/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:28:38 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/15 11:32:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void	ft_putstr(char *str);

int	main(void)
{
	char	*str;

	str = "This is a test string with %d all %x and a double %% here.";
	ft_putstr("This many arguments the line has: %d.\n");
}
