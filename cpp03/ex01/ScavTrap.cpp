/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:25:22 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:15:10 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("ScavTrap")
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->setHp(100);
	this->setEp(50);
	this->setAtk(20);
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	//No need to copy the name, it's the same type but not the same object
	this->setHp(rhs.getHp());
	this->setEp(rhs.getEp());
	this->setAtk(rhs.getAtk());

	std::cout << "ScavTrap assignation operator called" << std::endl;
	return (*this);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName();
	std::cout << " has enterred in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(std::string const	&target)
{
		std::string nameType = "ScavTrap";

	if (this->_hp <= 0)
	{
		std::cout<< nameType << " " << this->_name;
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
		std::cout<< nameType << " " << this->_name;
		std::cout << " has no more energy!" << std::endl;
	}
}