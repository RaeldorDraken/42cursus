/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:26:28 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 09:31:41 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.getIdea(i);
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.getIdea(i);
	std::cout << "Brain assignation operator called" << std::endl;
	return (*this);
}

std::string	Brain::getIdea(int i) const
{
	if (i < 0 || i > 99)
		return ("bad index");
	return (this->ideas[i]);
}

int	Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i > 99)
		return (1);
	this->ideas[i] = idea;

	return (0);
}
