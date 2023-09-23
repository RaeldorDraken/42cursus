/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:05:11 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/23 19:13:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type){}

Weapon::~Weapon(void){}

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string _type)
{
	this->type = _type;
}