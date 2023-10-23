/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:57:38 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:20:54 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Default constructor called for " << this->getType() << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src.getType())
{
	std::cout << "WrongCat Copy constructor called for " << this->getType() << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat Destructor called for " << this->getType() << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	this->setType(rhs.getType());
	std::cout << "WrongCat Assignation operator called for " << this->getType() << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->getType() << ": Mmm, You know, being a cat is nice but i wanna bark" << std::endl;
}
