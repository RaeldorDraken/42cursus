/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:54:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:08:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog constructor called for " << this->getType() << std::endl;
}

Dog::Dog(Dog const &src) : Animal(src.getType())
{
	std::cout << "Dog Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

Dog::~Dog(void)
{
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