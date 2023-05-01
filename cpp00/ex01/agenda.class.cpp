/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:39:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/01 11:02:59 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"agenda.class.hpp"
#include"agenda.h"

PhoneBook::PhoneBook(void)
{
	std::cout << "Phonebook constructor called"	<< std::endl;
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Phonebook destructor called"	<< std::endl;
	return;
}

void PhoneBook::ADD(void)
{
	char	input[512];
	
	std::cin >> input;
	std::cout << "ADD called: " << input << std::endl;
	return;
}

Test::Test(void)
{
	std::cout << "Test constructor called"	<< std::endl;
	return;
}

Test::~Test(void)
{
	std::cout << "Test destructor called"	<< std::endl;
	return;
}