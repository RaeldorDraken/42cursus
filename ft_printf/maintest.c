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

	s1 = ft_printf("Test with a pointer: %p \n", (void *)-1);
	printf("printf return: %d\n", s1);
	s2 = printf("Test with a pointer: %p \n", (void *)-1);
	printf("printf return: %d\n", s2);
}
