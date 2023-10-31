/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 11:01:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/31 11:07:52 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Floor.hpp"

Floor::Floor(void) : _first(NULL), _last(NULL), _nbMateria(0)
{
	std::cout << "Floor default constructor called" << std::endl;
}

Floor::Floor(Floor const & src) : _first(NULL), _last(NULL), _nbMateria(src._nbMateria)
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
	std::cout << "nbMateria: " << this->_nbMateria << std::endl;
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
	for (int i = 0; i < this->_nbMateria; i++)
	{
		if (this->getMateria(i)->getMateria() == materia)
			return ;
	}

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
	_nbMateria = countMateria();
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
	_nbMateria = countMateria();
}

void	Floor::eraseMateria(void)
{
	AMateriaFloor	*tmp;

	while (_nbMateria > 0)
	{
		tmp = this->_first;
		tmp->getMateria()->setIsDelete(true);
		if (this->_first->getNext() != NULL)
			this->_first = this->_first->getNext();
		else
			this->_first = NULL;
		delete tmp;
		_nbMateria--;
	}
	this->_first = NULL;
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

int		Floor::countMateria(void) const
{
	AMateriaFloor	*tmp = this->_first;
	int	i = 0;

	while (tmp != NULL)
	{
		tmp = tmp->getNext();
		i++;
	}
	return (i);
}

void	Floor::removeMateriaFloor(int idx)
{
	AMateriaFloor	*tmp = this->_first;
	int	i = 0;

	while (tmp != NULL && tmp->getNext() != NULL && i < idx)
	{
		tmp = tmp->getNext();
		i++;
	}
	if (tmp != NULL)
		this->delMateria(tmp);
	this->_nbMateria--;
}

AMateriaFloor	*Floor::getMateria(int idx) const
{
	AMateriaFloor	*tmp = this->_first;
	int	i = 0;

	while (tmp != NULL && tmp->getNext() != NULL && i < idx)
	{
		tmp = tmp->getNext();
		i++;
	}
	return (tmp);
}

int	Floor::getMateriaIdx(AMateria *materia) const
{
	AMateriaFloor	*tmp = this->_first;
	int	i = 0;

	while (tmp != NULL && tmp->getNext() != NULL && tmp->getMateria() != materia)
	{
		tmp = tmp->getNext();
		i++;
	}
	if (tmp != NULL && tmp->getMateria() == materia)
		return (i);
	return (-1);
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