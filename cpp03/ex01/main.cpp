/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/20 11:27:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap alpha("TERMINATOR");
	ClapTrap beta("Wall-E");

	std::cout << alpha.getName() << " HP: " << alpha.getHp() << std::endl;
	std::cout << alpha.getName() << " EP: " << alpha.getEp() << std::endl;
	std::cout << alpha.getName() << " ATK: " << alpha.getAtk() << std::endl;
	std::cout << beta.getName() << " HP: " << beta.getHp() << std::endl;
	std::cout << beta.getName() << " EP: " << beta.getEp() << std::endl;
	std::cout << beta.getName() << " ATK: " << beta.getAtk() << std::endl;
	alpha.attack(beta.getName());
	beta.takeDamage(alpha.getAtk());
	std::cout << alpha.getName() << " EP: " << alpha.getEp() << std::endl;
	std::cout << beta.getName() << " HP: " << beta.getHp() << std::endl;
	beta.beRepaired(5);
	std::cout << beta.getName() << " HP: " << beta.getHp() << std::endl;
	alpha.guardGate();

	return (0);
}