/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:56:33 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/23 18:58:42 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./PmergeMe \"1 2 3 4 5 6 7 8 9 10\"" << std::endl;
		return (1);
	}
	try
	{
		std::string str(argv[1]);
		PmergeMe::mergeMe(&str);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
