/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:48:34 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:28:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const & src) : AMateria(src)
{
}

Ice::~Ice(void)
{
}

Ice &	Ice::operator=(Ice const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AMateria*	Ice::clone(void) const
{
	return new Ice(*this);
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
