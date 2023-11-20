/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:38:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/20 23:44:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main(void)
{
	Form	f1("f1", 1, 1);
	Form	f2("f2", 150, 150);
	Form	f3("f3", 42, 42);
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 150);
	Bureaucrat	b3("b3", 42);

	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f3 << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	try
	{
		std::cout << "\tTrying to sign f1 by b2" << std::endl;
		f1.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << f1 << std::endl;

	try
	{
		std::cout << "\tTrying to sign f2 by b3" << std::endl;
		f2.beSigned(b3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << f2 << std::endl;

	try
	{
		std::cout << "\tTrying to sign f1 by b1" << std::endl;
		f1.beSigned(b1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << f1 << std::endl;

	try
	{
		std::cout << "\tTrying to sign f3 by b2" << std::endl;
		f1.beSigned(b1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << f3 << std::endl;

	try
	{
		std::cout << "\tTrying to sign f3 by b3" << std::endl;
		f3.beSigned(b3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << f3 << std::endl;
}