/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:38:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/22 09:48:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "------------------" << std::endl;
	std::cout << "Bureaucrat list" << std::endl;
	std::cout << "------------------" << std::endl;

	Bureaucrat	*b = new Bureaucrat("GoodBender", 1);
	Bureaucrat	*b2 = new Bureaucrat("UglyBender", 50);
	Bureaucrat	*b3 = new Bureaucrat("BadBender", 150);

	std::cout << *b;
	std::cout << *b2;
	std::cout << *b3;
	
	std::cout << "------------------" << std::endl;
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "------------------" << std::endl;

	PresidentialPardonForm	*ppf = new PresidentialPardonForm("DumbBender");

	std::cout << *ppf;
	b->executeForm(*ppf);
	b3->signForm(*ppf);
	b2->signForm(*ppf);
	b->signForm(*ppf);
	b3->executeForm(*ppf);
	b2->executeForm(*ppf);
	b->executeForm(*ppf);

	std::cout << "------------------" << std::endl;
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "------------------" << std::endl;

	RobotomyRequestForm	*rrf = new RobotomyRequestForm("DumbBender");

	std::cout << *rrf;
	b->executeForm(*rrf);
	b3->signForm(*rrf);
	b2->signForm(*rrf);	
	b->signForm(*rrf);
	b3->executeForm(*rrf);
	b2->executeForm(*rrf);
	b->executeForm(*rrf);
	b->executeForm(*rrf);
	b->executeForm(*rrf);
	b->executeForm(*rrf);

	std::cout << "------------------" << std::endl;
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "------------------" << std::endl;

	ShrubberyCreationForm	*scf = new ShrubberyCreationForm("DumbBender");

	std::cout << *scf;
	b->executeForm(*scf);
	b3->signForm(*scf);
	b2->signForm(*scf);
	b->signForm(*scf);
	b3->executeForm(*scf);
	b2->executeForm(*scf);
	b->executeForm(*scf);
	
	delete b;
	delete b2;
	delete b3;
	delete ppf;
	delete rrf;
	delete scf;
}