/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:39 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 10:59:46 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Animal.hpp"

Animal::Animal(void) : _type("Amoeba")
{
	std::cout << "Animal Default constructor called for " << this->getType() << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal _type constructor called for " << this->getType() << std::endl;
}

Animal::Animal(Animal const &src) : _type(src._type)
{
	std::cout << "Animal Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal Destructor called for " << this->getType() << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	this->_type = rhs.getType();
	std::cout << "Animal Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
}

void	Animal::makeSound(void) const
{
	std::cout << this->getType() << " is an animal with no sound" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Animal const &rhs)
{
	out << rhs.getType();
	return (out);
}