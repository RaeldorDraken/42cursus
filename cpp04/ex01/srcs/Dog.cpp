/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:54:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/24 00:15:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called for " << this->getType() << std::endl;
	_brain = new Brain();
	for (int i = 0; i < 100; i++)
		_brain->setIdea(i, "Dog idea num " + std::to_string(i));
}

Dog::Dog(Dog const &src) : Animal(src.getType())
{
	std::cout << "Dog Copy constructor called for " << this->getType() << std::endl;
	_brain = new Brain(*src._brain);
	*this = src;
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog Destructor called for " << this->getType() << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	this->setType(rhs.getType());
	std::cout << "Dog Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->getType() << ": Woof woof Awoooooooooooo! wan!" << std::endl;
}