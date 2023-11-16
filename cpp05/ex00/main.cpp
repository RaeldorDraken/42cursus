/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:38:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/16 23:13:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	//These two lines should throw exceptions
		//	Bureaucrat	b3("b3", 151);
		//	Bureaucrat	b4("b4", 0);
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 150);
	Bureaucrat	b5("b5", 42);
		//	std::cout << b3 << std::endl;
		//	std::cout << b4 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b5 << std::endl;
	try
	{
		std::cout << "\tTrying to increment b1 1 time" << std::endl;
		b1.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\tTrying to decrement b2 1 time" << std::endl;
		b2.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "\tTrying to decrement b5 1 time" << std::endl;
		b5.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << b5 << std::endl;

	try
	{
		std::cout << "\tTrying to increment b5 2 times" << std::endl;
		b5.incrementGrade();
		b5.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << b5 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;

	return (0);
}