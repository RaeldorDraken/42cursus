/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaFloor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:59:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/31 10:44:51 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AMateriaFloor.hpp"

AMateriaFloor::AMateriaFloor(void) : _next(NULL), _prev(NULL), _materia(NULL)
{
	std::cout << "AMateriaFloor default constructor called" << std::endl;
}

AMateriaFloor::AMateriaFloor(AMateria *materia) : _next(NULL), _prev(NULL), _materia(materia)
{
	std::cout << "AMateriaFloor _materia constructor called" << std::endl;
}

AMateriaFloor::AMateriaFloor(AMateriaFloor const & src) : _next(NULL), _prev(NULL), _materia(NULL)
{
	std::cout << "AMateriaFloor copy constructor called" << std::endl;
	*this = src;
}

AMateriaFloor::~AMateriaFloor(void)
{
	if (this->_materia)
		if (this->_materia->getIsDelete() == true)
			delete _materia;
	std::cout << "AMateriaFloor destructor called" << std::endl;
}

AMateriaFloor &AMateriaFloor::operator=(AMateriaFloor const &rhs)
{
	if (this != &rhs)
	{
		this->_next = rhs._next;
		this->_prev = rhs._prev;
		this->_materia = rhs._materia;
	}
	return (*this);
}

AMateriaFloor	*AMateriaFloor::getNext(void) const
{
	return (this->_next);
}

AMateriaFloor	*AMateriaFloor::getPrev(void) const
{
	return (this->_prev);
}

AMateria	*AMateriaFloor::getMateria(void) const
{
	return (this->_materia);
}

void	AMateriaFloor::setNext(AMateriaFloor *next)
{
	this->_next = next;
}

void	AMateriaFloor::setPrev(AMateriaFloor *prev)
{
	this->_prev = prev;
}
