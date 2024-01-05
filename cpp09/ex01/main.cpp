/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:42:56 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 15:54:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Użycie: ./rpn \"wyrażenie\"" << std::endl;
		std::cout << "Przykład: ./rpn \"5 2 + 3 * 4 -\"" << std::endl;
		std::cout << "Sorry, it was writing in polish :)" << std::endl;
		return (0);
	}
	RPN::rpn(argv[1]);
	return (0);
}