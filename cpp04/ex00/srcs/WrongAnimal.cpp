/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:57:28 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:25:39 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal Default constructor called for " << this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal _type constructor called for " << this->getType() << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : _type(src._type)
{
	std::cout << "WrongAnimal Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor called for " << this->getType() << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->_type = rhs.getType();
	std::cout << "WrongAnimal Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::setType(std::string type)
{
	this->_type = type;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->getType() << " is a wrong animal with no sound" << std::endl;
}

std::ostream &operator<<(std::ostream &out, WrongAnimal const &rhs)
{
	out << rhs.getType();
	return (out);
}
