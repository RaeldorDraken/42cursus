/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:52:18 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/10 11:46:23 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl harl;

	if (ac < 2)
	{
		std::cout << "Usage: ./harl <level>" << std::endl;
		return 1;
	}
	harl.complain(av[1]);
	// harl.complain("debug");
	// harl.complain("info");
	// harl.complain("warning");
	// harl.complain("error");
	// harl.complain("invalid");
	return 0;
}
