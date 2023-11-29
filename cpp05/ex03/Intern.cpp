/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:31 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/29 16:41:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	return ;
}

Intern::Intern(Intern const &src)
{
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	if (this != &rhs)
		;
	return (*this);
}

std::string forms[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

static void	lowercased(std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	}
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	int i;
	lowercased(form);
	for (i = 0; i < 3; i++)
	{
		if (form == forms[i])
			break ;
	}
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			std::cout << "Intern doesn't know this type of form" << std::endl;
	}
	return (NULL);
}