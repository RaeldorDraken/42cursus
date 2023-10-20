/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/20 11:27:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

int	main(void)
{
	FragTrap alpha("Bender");
	ScavTrap beta("Leela");
	ClapTrap gamma("Fry");
	
	std::cout << alpha.getName() << " HP: " << alpha.getHp() << std::endl;
	std::cout << alpha.getName() << " EP: " << alpha.getEp() << std::endl;
	std::cout << alpha.getName() << " ATK: " << alpha.getAtk() << std::endl;
	std::cout << beta.getName() << " HP: " << beta.getHp() << std::endl;
	std::cout << beta.getName() << " EP: " << beta.getEp() << std::endl;
	std::cout << beta.getName() << " ATK: " << beta.getAtk() << std::endl;
	std::cout << gamma.getName() << " HP: " << gamma.getHp() << std::endl;
	std::cout << gamma.getName() << " EP: " << gamma.getEp() << std::endl;
	std::cout << gamma.getName() << " ATK: " << gamma.getAtk() << std::endl;

	alpha.attack("Fry");
	gamma.takeDamage(5);
	std::cout << gamma.getName() << " HP: " << gamma.getHp() << std::endl;
	gamma.beRepaired(5);
	std::cout << gamma.getName() << " HP: " << gamma.getHp() << std::endl;
	alpha.highFivesGuys();

	return (0);
}