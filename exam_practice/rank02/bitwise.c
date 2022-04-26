/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:27:44 by eros-gir          #+#    #+#             */
/*   Updated: 2022/04/15 12:27:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

unsigned char	reverse_bits(unsigned char b)
{
	b =  (b & 0xF0) >> 4 | (b & 0x0F) << 4;
	b =  (b & 0xCC) >> 2 | (b & 0x33) << 2;
	b =  (b & 0xAA) >> 1 | (b & 0x55) << 1;
	return (b);
}

unsigned char	swap_bits(unsigned char b)
{
	return ((b >> 4) | (b << 4));
}

void	print_bits(unsigned char octet)
{
	int	i = 256;
	while (i >>= 1)
	{
		if (octet & i)
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

int	main(void)
{
	int i = 170;
	printf("Input: %d\n", i);
	printf("Original: \n");
	print_bits(i);
	printf("\nSwap: \n");
	print_bits(swap_bits(i));
	printf("\nReverse: \n");
	print_bits(reverse_bits(i));
	printf("\n");
}
