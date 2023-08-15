/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AgendaClass.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:39:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/08/15 15:17:32 by eros-gir         ###   ########.fr       */
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
	std::string input;
	std::string buff;

	phonebook->_index++;
	if (phonebook->_index > 7)
	{
		std::cout << "Phonebook is full" << std::endl;
		std::cout << "Do you want to replace the first entry?" << std::endl;
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (input == "yes" || input == "y")	
			phonebook->_index = 0;
		else return;
	}
	std::cout << "First Name: ";
	std::cin >> input;
	getline(std::cin, buff);
	input += buff;
	phonebook->contact[phonebook->_index].SetFirstName(input);
	std::cout << "Last Name: ";
	std::cin >> input;
	getline(std::cin, buff);
	input += buff;
	phonebook->contact[phonebook->_index].SetLastName(input);
	std::cout << "Nickname: ";
	std::cin >> input;
	getline(std::cin, buff);
	input += buff;
	phonebook->contact[phonebook->_index].SetNickname(input);
	std::cout << "Phone Number: ";
	std::cin >> input;
	getline(std::cin, buff);
	input += buff;
	phonebook->contact[phonebook->_index].SetPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::cin >> input;
	getline(std::cin, buff);
	input += buff;
	phonebook->contact[phonebook->_index].SetDarkestSecret(input);
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
		std::string _fname = ft_truncate(phonebook->contact[i].GetFirstName(), 10, true);
		std::string _lname = ft_truncate(phonebook->contact[i].GetLastName(), 10, true);
		std::string _nname = ft_truncate(phonebook->contact[i].GetNickname(), 10, true);
		std::string _pnumber = ft_truncate(phonebook->contact[i].GetPhoneNumber(), 10, true);
		std::string _dsecret = ft_truncate(phonebook->contact[i].GetDarkestSecret(), 10, true);
		std::string _index = ft_truncate(std::to_string(i + 1), 10, true);
		std::cout <<  _index << "|" << _fname << "|" << _lname << "|" << _nname << std::endl;
	}
	std::cout << "Select an index: ";
	std::cin >> index;
	index--;
	switch (index)
	{
		default:
			std::cout << "Invalid index" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
		case 0:	case 1:	case 2:	case 3:	case 4:	case 5:	case 6:	case 7:
			std::cout << "First Name: " << phonebook->contact[index].GetFirstName() << std::endl;
			std::cout << "Last Name: " << phonebook->contact[index].GetLastName() << std::endl;
			std::cout << "Nickname: " << phonebook->contact[index].GetNickname() << std::endl;
			std::cout << "Phone Number: " << phonebook->contact[index].GetPhoneNumber() << std::endl;
			std::cout << "Darkest Secret: " << phonebook->contact[index].GetDarkestSecret() << std::endl;
		break;
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

		void		SetFirstName(std::string str);
		std::string	GetFirstName(void);
		void		SetLastName(std::string str);
		std::string	GetLastName(void);
		void		SetNickname(std::string str);
		std::string	GetNickname(void);
		void		SetPhoneNumber(std::string str);
		std::string	GetPhoneNumber(void);
		void		SetDarkestSecret(std::string str);
		std::string	GetDarkestSecret(void);

int	Contact::SetFirstName(std::string str)
{
	this->first_name = str;
	return (0);
}

std::string	Contact::GetFirstName(void)
{
	return (this->first_name);
}

int	Contact::SetLastName(std::string str)
{
	this->last_name = str;
	return (0);
}

std::string	Contact::GetLastName(void)
{
	return (this->last_name);
}

int	Contact::SetNickname(std::string str)
{
	this->nickname = str;
	return (0);
}

std::string Contact::GetNickname(void)
{
	return (this->nickname);
}

int Contact::SetPhoneNumber(std::string str)
{
	this->phone_number = str;
	return (0);
}

std::string Contact::GetPhoneNumber(void)
{
	return (this->phone_number);
}

int Contact::SetDarkestSecret(std::string str)
{
	this->darkest_secret = str;
	return (0);
}

std::string Contact::GetDarkestSecret(void)
{
	return (this->darkest_secret);
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