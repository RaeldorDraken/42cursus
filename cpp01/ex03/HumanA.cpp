/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:17:37 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/29 20:47:23 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : name(_name), weapon(_weapon){}

HumanA::~HumanA(void){}

void HumanA::attack(void)
{
	std::cout << getName() << " attacks with their " << getWeapon().getType() << std::endl;
}

void HumanA::setName(std::string _name)
{
	this->name = _name;
}

void HumanA::setWeapon(Weapon &_weapon)
{
	this->weapon = _weapon;
}

std::string HumanA::getName(void)
{
	return (this->name);
}

Weapon HumanA::getWeapon(void)
{
	return (this->weapon);
}