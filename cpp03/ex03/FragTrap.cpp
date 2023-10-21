/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:50:35 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:12:43 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("FragTrap")
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->setHp(100);
	this->setEp(100);
	this->setAtk(30);
	std::cout << "FragTrap constructor called" << std::endl;
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
	this->setHp(rhs.getHp());
	this->setEp(rhs.getEp());
	this->setAtk(rhs.getAtk());

	std::cout << "FragTrap assignation operator called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::string input;
	std::cout << this->getName() <<": I wanna be popular too!" << std::endl;
	std::cout << "Type <high five> to give him a high five" << std::endl;
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
	return (this->getHp());
}

int		FragTrap::getFrEP(void) const
{
	return (this->getEp());
}

int		FragTrap::getFrAtk(void) const
{
	return (this->getAtk());
}
