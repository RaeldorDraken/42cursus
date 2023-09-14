/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:45:10 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/09 20:28:22 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*arrzombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		arrzombie[i].setName(name);
	return (arrzombie);
}

int	Zombie::setName(std::string _name)
{
	name = _name;
	return (0);
}

std::string	Zombie::getName(void)
{
	std::cout << name << std::endl;
	return (0);
}