/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:01:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/28 17:27:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Floor.hpp"

Floor::Floor(void) : _first(NULL), _last(NULL), _nbMateria(0)
{
	std::cout << "Floor default constructor called" << std::endl;
}

Floor::Floor(Floor const & src) : _first(NULL), _last(NULL), _nbMateria(0)
{
	std::cout << "Floor copy constructor called" << std::endl;
	if (src._first != NULL)
	{
		AMateriaFloor	*tmp = src._first;

		while (tmp != NULL)
		{
			this->addMateria(tmp->getMateria());
			tmp = tmp->getNext();
		}
	}
	*this = src;
}

Floor::~Floor(void)
{
	std::cout << "Floor destructor called" << std::endl;
	this->eraseMateria();
}

Floor &Floor::operator=(Floor const & rhs)
{
	if (this != &rhs)
	{
		this->_first = rhs._first;
		this->_last = rhs._last;
		this->_nbMateria = rhs._nbMateria;
	}
	return (*this);
}

void	Floor::addMateria(AMateria *materia)
{
	AMateriaFloor	*newMateria = new AMateriaFloor(materia);

	if (this->_first == NULL)
	{
		this->_first = newMateria;
		this->_last = newMateria;
	}
	else
	{
		this->_last->setNext(newMateria);
		newMateria->setPrev(this->_last);
		this->_last = newMateria;
	}
	this->_nbMateria++;
}

void	Floor::delMateria(AMateriaFloor *materia)
{
	if (materia == this->_first)
	{
		this->_first = materia->getNext();
		if (this->_first != NULL)
			this->_first->setPrev(NULL);
	}
	else if (materia == this->_last)
	{
		this->_last = materia->getPrev();
		if (this->_last != NULL)
			this->_last->setNext(NULL);
	}
	else
	{
		materia->getPrev()->setNext(materia->getNext());
		materia->getNext()->setPrev(materia->getPrev());
	}
	delete materia;
	this->_nbMateria--;
}

void	Floor::eraseMateria(void)
{
	AMateriaFloor	*tmp;

	while (this->_first != NULL)
	{
		tmp = this->_first;
		this->_first = this->_first->getNext();
		delete tmp;
	}
	this->_last = NULL;
	this->_nbMateria = 0;
}

AMateriaFloor	*Floor::getFirst(void) const
{
	return (this->_first);
}

AMateriaFloor	*Floor::getLast(void) const
{
	return (this->_last);
}

int		Floor::getNbMateria(void) const
{
	return (this->_nbMateria);
}

void	Floor::printFloor(void) const
{
	AMateriaFloor	*tmp;
	int				i = 0;


	std::cout << std::endl << "Floor: ";
	if (this->_first != NULL)
	{
		tmp = this->getFirst();
		while (tmp)
		{
			std::cout << tmp->getMateria()->getType() << " ";
			tmp = tmp->getNext();
			i++;
		}
	}
	else
		std::cout << "NULL";
	std::cout << std::endl;
}