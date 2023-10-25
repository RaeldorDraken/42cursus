/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:54:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 10:05:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::ostringstream oss;
	std::string str;

	_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		oss << "Dog idea num " << i;
		str = oss.str();
		_brain->setIdea(i, str);
		oss.str("");
	}
	std::cout << "Dog constructor called for " << this->getType() << std::endl;
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

Brain	*Dog::getBrain(void) const
{
	return (_brain);
}
