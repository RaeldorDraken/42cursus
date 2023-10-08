/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:27:38 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/08 19:07:55 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

int	main(int ac, char **av)
{
	StringReplace	sr;
	if (ac != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	if (sr.find_replace(av[1], av[2], av[3]))
		return (1);
	return (0);
}