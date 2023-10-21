/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:27:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:04:21 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	this->_name = name;
	this->_hp = this->FragTrap::getFrHP();
	this->_ep = this->ScavTrap::getScEP();
	this->_atk = this->FragTrap::getFrAtk();
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src._name), FragTrap(src._name), ScavTrap(src._name)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	//Nombre no hace falta debemos preservar la individualidad de cada objeto
	this->_hp = src._hp;
	this->_ep = src._ep;
	this->_atk = src._atk;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hp = rhs._hp;
	this->_ep = rhs._ep;
	this->_atk = rhs._atk;

	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}

int		DiamondTrap::getHP(void) const
{
	return (this->_hp);
}

int		DiamondTrap::getEP(void) const
{
	return (this->_ep);
}

int		DiamondTrap::getAtk(void) const
{
	return (this->_atk);
}

std::string DiamondTrap::getName(void) const
{
	return (this->_name);
}

void	DiamondTrap::setHP(int hp)
{
	this->_hp = hp;
}

void	DiamondTrap::setEP(int ep)
{
	this->_ep = ep;
}

void	DiamondTrap::setAtk(int atk)
{
	this->_atk = atk;
}

void	DiamondTrap::setName(std::string name)
{
	this->_name = name;
}