/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/24 22:30:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/polymorph.h"
#include"../incl/Animal.hpp"
#include"../incl/Dog.hpp"
#include"../incl/Cat.hpp"

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

	std::cout << "\nMaking some sounds...\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Animal " << i << ": ";
		group[i]->makeSound();
	}

	std::cout << "\nDeleting the group...\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Deleting animal " << i << " : ";
		if (i % 2 == 0)
			std::cout << "dog" << std::endl;
		else
			std::cout << "cat" << std::endl;
		delete group[i];
	}
	
	return (0);
}
