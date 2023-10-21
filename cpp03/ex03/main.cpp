/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:06:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:11:09 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	diamond("IronGiant");

	std::cout << diamond.getName() << " HP: " << diamond.getHp() << std::endl;
	std::cout << diamond.getName() << " EP: " << diamond.getEp() << std::endl;
	std::cout << diamond.getName() << " ATK: " << diamond.getAtk() << std::endl;

	diamond.attack("World");
	diamond.whoAmI();
	diamond.guardGate();
	diamond.highFivesGuys();

	return (0);
}