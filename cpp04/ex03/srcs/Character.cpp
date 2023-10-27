/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 13:30:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Character.hpp"

Character::Character(void) : _name("default")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	std::cout << "Character _name constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src) : _name(src._name), _nbMateria(src._nbMateria)
{
	std::cout << "Character copy constructor called" << std::endl;
	for ( int i = 0; i < 4; i++ )
	{
		this->_inventory[ i ] = NULL;
		if ( src._inventory[ i ] != NULL )
			this->_inventory[ i ] = src._inventory[ i ]->clone();
	}
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
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
	}
	return *this;
}

std::string const &	Character::getName(void) const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	if (this->_nbMateria < 4 && m)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_inventory[i])
			{
				this->_inventory[i] = m;
				this->_nbMateria++;
				break;
			}
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
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

void	Character::printTrash(void)
{
	std::cout << "Trash: ";
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			std::cout << this->_inventory[i]->getTrash() << " ";
		else
			std::cout << "NULL ";
	}
	std::cout << std::endl;
}
