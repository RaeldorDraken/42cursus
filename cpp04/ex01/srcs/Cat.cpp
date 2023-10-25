/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:50:27 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 10:05:20 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::ostringstream oss;
	std::string str;

	_brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		oss << "Cat idea num " << i;
		str = oss.str();
		_brain->setIdea(i, str);
		oss.str("");
	}
	std::cout << "Cat Default constructor called for " << this->getType() << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src.getType())
{
	_brain = new Brain(*src._brain);
	std::cout << "Cat Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

Cat::~Cat(void)
{
	delete _brain;
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

Brain	*Cat::getBrain(void) const
{
	return (_brain);
}
