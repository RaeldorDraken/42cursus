/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:30:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/01 13:13:15 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Agenda.h"
#include"AgendaClass.hpp"

int	main(void)
{
	char 		buff[512];
	PhoneBook	phonebook;
	
	phonebook._exit = false;
	phonebook._index = -1;
	std::cout << "* MY AMAZING PHONEBOOK *" << std::endl;
	while (!phonebook._exit)
	{
		std::cout << "Enter a command: ";
		std::cin >> buff;
		std::cout << "You entered: [" << buff << "]" << std::endl;
		if (!std::strcmp(buff, "ADD") || !std::strcmp(buff, "add"))
			phonebook.ADD(&phonebook);
		else if (!std::strcmp(buff, "EXIT") || !std::strcmp(buff, "exit"))
			phonebook.EXIT(&phonebook);
		else if (!std::strcmp(buff, "SEARCH") || !std::strcmp(buff, "search"))
			phonebook.SEARCH(&phonebook);
		else	std::cout << "Invalid command" << std::endl;
	}
	return(0);
}