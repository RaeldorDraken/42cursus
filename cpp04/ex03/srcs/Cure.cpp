/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:54:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:28:04 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const & src) : AMateria(src)
{
}

Cure::~Cure(void)
{
}

Cure &	Cure::operator=(Cure const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

AMateria*	Cure::clone(void) const
{
	return new Cure(*this);
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
