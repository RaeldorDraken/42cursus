/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 10:28:38 by eros-gir          #+#    #+#             */
/*   Updated: 2022/03/21 12:29:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include"ft_printf.h"

int	main(void)
{
	int	s1;
	int	s2;

	s1 = ft_printf("A test string with a pointer p: %x \n", 123456);
	printf("%d\n", s1);
	s2 = printf("A test string with a pointer p: %x \n", 123456);
	printf("%d\n", s2);
}
