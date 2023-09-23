/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:17:37 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/23 19:44:42 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	name = _name;
	weapon = NULL;
}

HumanB::~HumanB(void){}

void HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << getName() << " has no weapon" << std::endl;
	else
		std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

void HumanB::setName(std::string _name)
{
	this->name = _name;
}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

std::string HumanB::getName(void)
{
	return (this->name);
}

Weapon HumanB::getWeapon(void)
{
	return (*this->weapon);
}