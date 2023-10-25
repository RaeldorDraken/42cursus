/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:39 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/AAnimal.hpp"

AAnimal::AAnimal(void) : _type("Amoeba")
{
	std::cout << "Animal Default constructor called for " << this->getType() << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Animal _type constructor called for " << this->getType() << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) : _type(src._type)
{
	std::cout << "Animal Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal Destructor called for " << this->getType() << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	this->_type = rhs.getType();
	std::cout << "Animal Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

void	AAnimal::setType(std::string type)
{
	this->_type = type;
}

void	AAnimal::makeSound(void) const
{
	std::cout << this->getType() << " is an animal with no sound" << std::endl;
}

std::ostream &operator<<(std::ostream &out, AAnimal const &rhs)
{
	out << rhs.getType();
	return (out);
}