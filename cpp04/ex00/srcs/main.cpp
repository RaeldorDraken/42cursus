/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:25:04 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/polymorph.h"

int	main()
{
	const Animal* undef = new Animal();
	const Animal* catto = new Cat();
	const Animal* doggo = new Dog();
	const WrongAnimal* wrong = new WrongCat();

	std::cout << std::endl;
	std::cout << "undef->getType(): " << undef->getType() << std::endl;
	std::cout << "catto->getType(): " << catto->getType() << std::endl;
	std::cout << "doggo->getType(): " << doggo->getType() << std::endl;
	std::cout << "wrong->getType(): " << wrong->getType() << std::endl;
	std::cout << std::endl;

	catto->makeSound();
	doggo->makeSound();
	undef->makeSound();
	wrong->makeSound();

	std::cout << std::endl;

	delete undef;
	delete catto;
	delete doggo;
	delete wrong;

	return (0);
}
