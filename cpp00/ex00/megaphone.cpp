/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:34:37 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/26 10:24:26 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main(int ac, char** av) 
{
	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				std::cout << (char)std::toupper(av[i][j]);
			}
		}
		std::cout << std::endl;
	}
	return (0);
}