/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AgendaClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:39:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/01 13:53:48 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AgendaClass.hpp"

PhoneBook::PhoneBook(void)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void	PhoneBook::ADD(PhoneBook *phonebook)
{
	char	input[512];
	phonebook->_index++;
	if (phonebook->_index > 7)
	{
		std::cout << "Phonebook is full" << std::endl;
		std::cout << "Do you want to replace the first entry?" << std::endl;
		std::cin >> input;
		if (!std::strcmp(input, "yes") || !std::strcmp(input, "y"))	phonebook->_index = 0;
		else return;
	}
	std::cout << "First Name: ";
	std::cin >> input;
	phonebook->contact[phonebook->_index].first_name = input;
	std::cout << "Last Name: ";
	std::cin >> input;
	phonebook->contact[phonebook->_index].last_name = input;
	std::cout << "Nickname: ";
	std::cin >> input;
	phonebook->contact[phonebook->_index].nickname = input;
	std::cout << "Phone Number: ";
	std::cin >> input;
	phonebook->contact[phonebook->_index].phone_number = input;
	std::cout << "Darkest Secret: ";
	std::cin >> input;
	phonebook->contact[phonebook->_index].darkest_secret = input;
	return;
}

void	PhoneBook::SEARCH(PhoneBook *phonebook)
{	
	std::string _fname;
	std::string _lname;
	std::string _nname;
	std::string _pnumber;
	std::string _dsecret;
	int			index = 0;
	
	std::cout << "INDEX     " << "|" << "FIRST NAME" << "|" << "LAST NAME " << "|" << "NICKNAME " << std::endl;
	for(int i = 0; i < 8; i++)
	{
		std::string _fname = ft_truncate(phonebook->contact[i].first_name, 10, true);
		std::string _lname = ft_truncate(phonebook->contact[i].last_name, 10, true);
		std::string _nname = ft_truncate(phonebook->contact[i].nickname, 10, true);
		std::string _pnumber = ft_truncate(phonebook->contact[i].phone_number, 10, true);
		std::string _dsecret = ft_truncate(phonebook->contact[i].darkest_secret, 10, true);
		std::string _index = ft_truncate(std::to_string(i + 1), 10, true);
		std::cout <<  _index << "|" << _fname << "|" << _lname << "|" << _nname << std::endl;
	}
	std::cout << "Select an index: ";
	std::cin >> index;
	index--;
	if (index > 7 || index < 0)
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	else
	{
		std::cout << "First Name: " << phonebook->contact[index].first_name << std::endl;
		std::cout << "Last Name: " << phonebook->contact[index].last_name << std::endl;
		std::cout << "Nickname: " << phonebook->contact[index].nickname << std::endl;
		std::cout << "Phone Number: " << phonebook->contact[index].phone_number << std::endl;
		std::cout << "Darkest Secret: " << phonebook->contact[index].darkest_secret << std::endl; 
	}
	return;
}

void	PhoneBook::EXIT(PhoneBook *phonebook)
{
	char	input[512];
	
	std::cout << "All data will be lost. Are you sure to exit?" << std::endl;
	std::cin >> input;
	if (!std::strcmp(input, "yes") || !std::strcmp(input, "y"))	phonebook->_exit = true;
	else	phonebook->_exit = false;
	return;
}

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

std::string ft_truncate(std::string str, size_t width, bool ellip)
{
	if (str.length() > width)
	{
		if (ellip && width > 3)
			return (str.substr(0, width - 1) + ".");
		else
			return (str.substr(0, width));
	}
	else
	{
		while (str.length() < width)
			str += " ";
	}
	return (str);
}