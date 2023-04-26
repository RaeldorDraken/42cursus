/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:30:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/26 12:24:53 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"agenda.h"
#include"agenda.class.hpp"

int	main(void)
{
	char 	buff[512];
	Test	instance;
	PhoneBook	phonebook;
	
	std::cout << "* MY AMAZING PHONEBOOK *" << std::endl;
	std::cout << "Enter a command: ";
	std::cin >> buff;
	std::cout << "You entered : [" << buff << "]" << std::endl;
	if (!std::strcmp(buff, "ADD"))
	{
		phonebook.ADD();
	}
	
	return(0);
}