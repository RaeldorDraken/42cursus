/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/31 10:24:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Character.hpp"

Character::Character(void) : _name("default"), _trash(NULL)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_nbMateria = 0;
}

Character::Character(std::string const & name, Floor *trash) : _name(name), _trash(trash)
{
	std::cout << "Character _name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_nbMateria = 0;
}

Character::Character(Character const & src) : _name(src._name), _nbMateria(src._nbMateria), _trash(src._trash)
{
	std::cout << "Character copy constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		this->_inventory[ i ] = NULL;
		if (src._inventory[ i ] != NULL)
			this->_inventory[ i ] = src._inventory[ i ]->clone();
		this->_nbMateria++;
	}
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = rhs._inventory[i]->clone();
		}
		this->_nbMateria = rhs._nbMateria;
		this->_trash = rhs._trash;
	}
	return *this;
}

std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	int j = 0;

	if (m != NULL && m->getIsEquiped() == true)
		std::cout << "Character trying to equip already equipped materia" << std::endl;
	else if (m != NULL && m->getIsFloor() == true)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				std::cout << "Equiping " << m->getType() << std::endl;
				this->_trash->removeMateriaFloor(this->_trash->getMateriaIdx(m));
				this->_inventory[i] = m;
				m->setIsEquiped(true);
				m->setIsFloor(false);
				this->_nbMateria++;
				break ;
			}
		}
	}
	else if (m == NULL)
		std::cout << "Character trying to equip NULL materia" << std::endl;
	else if (this->_nbMateria < 4 && m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] == NULL)
			{
				std::cout << "Equiping " << m->getType() << std::endl;
				this->_inventory[i] = m;
				m->setIsEquiped(true);
				m->setIsDelete(false);
				this->_nbMateria++;
				break ;
			}
		}
	}
	else
	{
		std::cout << "Character trying to equip more than 4 materias" << std::endl;
		this->_trash->addMateria(m);
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << "Unequiping " << this->_inventory[idx]->getType() << std::endl;
		this->_trash->addMateria(this->_inventory[idx]);
		this->_inventory[idx]->setIsEquiped(false);
		this->_inventory[idx]->setIsFloor(true);
		this->_inventory[idx] = NULL;
		this->_nbMateria--;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}

//testing functions

void	Character::printMaterias(void)
{
	std::cout << "Materias: ";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << this->_inventory[i]->getType() << " ";
		else
			std::cout << "NULL ";
	}
	std::cout << std::endl;
}
