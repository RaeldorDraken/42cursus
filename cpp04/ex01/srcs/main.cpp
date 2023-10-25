/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 10:06:31 by eros-gir         ###   ########.fr       */
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
		std::cout << std::endl;
	}

	std::cout << "\nMaking some sounds...\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Animal " << i << ": ";
		group[i]->makeSound();
		std::cout << std::endl;
	}

	std::cout << "\nTesting the brain...\n" << std::endl;

	for (i = 0; i < 10; i++)
	{
		std::cout << "Animal " << i << ": ";
		if (i % 2 == 0)
			std::cout << "dog" << std::endl;
		else
			std::cout << "cat" << std::endl;
		for (int j = 0; j < 5; j++)
		{
			if (group[i] != NULL && group[i]->getBrain() != NULL)
				std::cout << group[i]->getBrain()->getIdea(j) << std::endl;
			else
				std::cout << "Animal does not have a brain." << std::endl;
		}
		std::cout << std::endl;
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
		std::cout << std::endl;
	}

	return (0);
}