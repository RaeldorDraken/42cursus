/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:38:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/15 10:44:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 150);
	Bureaucrat	b3("b3", 151);
	Bureaucrat	b4("b4", 0);
	Bureaucrat	b5("b5", 42);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;

	return (0);
}