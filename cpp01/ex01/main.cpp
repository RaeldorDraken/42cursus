/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:45:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/09 21:08:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;
	int		N = 5;
	std::string name = "Pepito";

	zombie = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
	{
		std::cout << "Zombie " << i << " name: ";
		zombie[i].announce();
		delete &zombie[i];
	}

	return (0);
}