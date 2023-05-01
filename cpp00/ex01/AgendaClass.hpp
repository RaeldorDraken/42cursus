/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AgendaClass.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:16 by eros-gir          #+#    #+#             */
/*   Updated: 2023/05/01 13:15:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENDA_CLASS_HPP
# define AGENDA_CLASS_HPP
# include"Agenda.h"

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	ADD(PhoneBook *phonebook);
		void	SEARCH(PhoneBook *phonebook);
		void	EXIT(PhoneBook *phonebook);
		bool	_exit;
		int		_index;
		Contact	contact[8];
};

std::string ft_truncate(std::string str, size_t width, bool ellip);

#endif