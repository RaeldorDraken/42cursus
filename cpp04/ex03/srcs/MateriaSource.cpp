/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:26:29 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/01 18:56:14 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _count(0)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) : _count(src._count)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	int	i = 0;

	while (i < MAX_MATERIA)
	{
		this->_materia[i] = NULL;
		if (src._materia[i] != NULL)
			this->_materia[i] = src._materia[i]->clone();
		i++;
	}
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		this->_materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < MAX_MATERIA; i++)
		{
			if (this->_materia[i])
				delete this->_materia[i];
			this->_materia[i] = NULL;
			if (rhs._materia[i] != NULL)
				this->_materia[i] = rhs._materia[i]->clone();
		}
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (this->_count == -1)
	{
		if (m != NULL)
			delete m;
		return ;
	}
	for (int i = 0; i < MAX_MATERIA; i++)
		if (this->_materia[i] == m)
			return ;
	this->_materia[this->_count] = m;
	this->_count = this->_count + 1 >= MAX_MATERIA ? -1 : this->_count + 1;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIA; i++)
	{
		if (this->_materia[i] && this->_materia[i]->getType() == type)
			return this->_materia[i]->clone();
	}
	return NULL;
}
