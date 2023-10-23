/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:50:27 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:18:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat Default constructor called for " << this->getType() << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src.getType())
{
	std::cout << "Cat Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Cat Destructor called for " << this->getType() << std::endl;
}

Cat &Cat::operator=(Cat const &rhs)
{
	this->setType(rhs.getType());
	std::cout << "Cat Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->getType() << ": purr" << std::endl;
}