/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:30:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/08/15 15:25:31 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AgendaClass.hpp"

int	main(void)
{
	std::string	buff;
	PhoneBook	phonebook;
	
	phonebook._exit = false;
	phonebook._index = -1;
	std::cout << "* MY AMAZING PHONEBOOK *" << std::endl;
	while (!phonebook._exit)
	{
		std::cout << "Enter a command: ";
		std::cin >> buff;
		std::cout << "You entered: [" << buff << "]" << std::endl;
		if (buff == "ADD" || buff == "add" || buff == "Add")
			phonebook.ADD(&phonebook);
		else if (buff == "EXIT" || buff == "exit" || buff == "Exit")
			phonebook.EXIT(&phonebook);
		else if (buff == "SEARCH" || buff == "search" || buff == "Search")
			phonebook.SEARCH(&phonebook);
		else	std::cout << "Invalid command" << std::endl;
	}
	return(0);
}