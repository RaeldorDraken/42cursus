/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:07:15 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:14:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("ClapTrap"), _hp(10), _ep(10), _atk(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _name(src._name), _hp(src._hp), _ep(src._ep), _atk(src._atk)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	//No need to copy the name, it's the same type but not the same object
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_atk = rhs._atk;

	std::cout << "ClapTrap assignation operator called" << std::endl;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::string nameType = "ClapTrap";

	if (this->_hp <= 0)
	{
		std::cout << nameType << this->_name;
		std::cout << " is dead!" << std::endl;
	}
	else if (this->_ep > 0)
	{
		this->_ep -= 1;
		std::cout<< nameType << " " << this->_name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_atk;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << nameType << this->_name;
		std::cout << " has no more energy!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp > 0)
	{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " takes " << amount << " points of damage!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is already dead!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int maxHp = 10;
	
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is dead!" << std::endl;
	}
	else if (this->_ep > (int)amount)
	{
		if (this->_hp + (int)amount > maxHp)
			amount = maxHp - this->_hp;
		this->_hp += amount;
		this->_ep -= amount;
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is repaired for " << amount;
		std::cout << " points of energy!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " has not enough energy!" << std::endl;
	}
}	

//Extra functions for testing purposes

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHp(void) const
{
	return (this->_hp);
}

int	ClapTrap::getEp(void) const
{
	return (this->_ep);
}

int	ClapTrap::getAtk(void) const
{
	return (this->_atk);
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHp(int hp)
{
	this->_hp = hp;
}

void	ClapTrap::setEp(int ep)
{
	this->_ep = ep;
}

void	ClapTrap::setAtk(int atk)
{
	this->_atk = atk;
}