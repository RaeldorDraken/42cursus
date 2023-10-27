/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:21:29 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 13:29:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AMateria.hpp"

AMateria::AMateria(void) : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria _type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & src) : _type(src._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &	AMateria::getType(void) const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const &	AMateria::getTrash(void) const
{
	return this->_trash;
}
