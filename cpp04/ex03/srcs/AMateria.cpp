/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:21:29 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 12:06:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AMateria.hpp"

AMateria::AMateria(void) : _type("default"), _isEquiped(false)
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type), _isEquiped(false)
{
	std::cout << "AMateria _type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : _type(src._type), _isEquiped(src._isEquiped)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_isEquiped = rhs._isEquiped;
	}
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}

bool	AMateria::getIsEquiped(void) const
{
	return this->_isEquiped;
}

void	AMateria::setIsEquiped(bool equip)
{
	this->_isEquiped = equip;
}
