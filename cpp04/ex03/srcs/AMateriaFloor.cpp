/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaFloor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:59:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/28 11:19:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AMateriaFloor.hpp"

AMateriaFloor::AMateriaFloor(void) : _next(NULL), _prev(NULL), _materia(NULL), _erase(false)
{
	std::cout << "AMateriaFloor default constructor called" << std::endl;
}

AMateriaFloor::AMateriaFloor(AMateria *materia) : _next(NULL), _prev(NULL), _materia(materia), _erase(false)
{
	std::cout << "AMateriaFloor _materia constructor called" << std::endl;
}

AMateriaFloor::AMateriaFloor(AMateriaFloor const & src) : _next(NULL), _prev(NULL), _materia(NULL), _erase(false)
{
	std::cout << "AMateriaFloor copy constructor called" << std::endl;
	*this = src;
}

AMateriaFloor::~AMateriaFloor(void)
{
	std::cout << "AMateriaFloor destructor called" << std::endl;
}

AMateriaFloor &AMateriaFloor::operator=(AMateriaFloor const & rhs)
{
	if (this != &rhs)
	{
		this->_next = rhs._next;
		this->_prev = rhs._prev;
		this->_materia = rhs._materia;
		this->_erase = rhs._erase;
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

void	AMateriaFloor::setErase(bool erase)
{
	this->_erase = erase;
}
