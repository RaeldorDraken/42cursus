/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/24 00:05:36 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/polymorph.h"

int	main()
{
	const Animal* group[10];
	int i;
	
	std::cout << "Setting up the group...\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Creating animal " << i << " : ";
		if (i % 2 == 0)
		{
			std::cout << "dog" << std::endl;
			group[i] = new Dog();
		}
		else
		{
			std::cout << "cat" << std::endl;
			group[i] = new Cat();
		}
	}
	

	return (0);
}
