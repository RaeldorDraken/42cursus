/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:50:35 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 17:17:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAtk(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	this->setHp(100);
	this->setEp(100);
	this->setAtk(30);
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
{
	//No need to copy the name, it's the same type but not the same object
	this->FragTrap::setHp(rhs.getHp());
	this->FragTrap::setEp(rhs.getEp());
	this->FragTrap::setAtk(rhs.getAtk());

	std::cout << "FragTrap assignation operator called" << std::endl;
	return (*this);
}

void	FragTrap::attack(std::string const	&target)
{
		std::string nameType = "FragTrap";

	if (this->_hp <= 0)
	{
		std::cout << nameType << this->_name;
		std::cout << " is dead!" << std::endl;
	}
	else if (this->_ep > 0)
	{
		this->_ep -= 1;
		std::cout << nameType << this->_name;
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

void	FragTrap::highFivesGuys(void)
{
	std::string input;
	std::cout << this->getName() <<": I wanna be popular too!" << std::endl;
	std::cout << "Type <high five> to give him a high five" << std::endl;
	std::cout << "input> " << std::flush;
	std::getline(std::cin, input);
	if (input == "high five")
	{
		std::cout << "FragTrap " << this->getName();
		std::cout << " is happy" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->getName();
		std::cout << " is sad" << std::endl;
	}
}

int		FragTrap::getFrHP(void) const
{
	return (100);
}

int		FragTrap::getFrEP(void) const
{
	return (100);
}

int		FragTrap::getFrAtk(void) const
{
	return (30);
}
