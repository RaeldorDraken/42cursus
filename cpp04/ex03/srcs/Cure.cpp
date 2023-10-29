/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 11:40:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	this->_type = src._type;
	this->_isEquiped = false;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AMateria	*Cure::clone(void) const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
