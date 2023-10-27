/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:01:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:28:02 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../incl/Character.hpp"

Character::Character(void) : _name("default")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src)
{
	*this = src;
}

Character::~Character(void)
{
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
		this->_name = rhs._name;
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
