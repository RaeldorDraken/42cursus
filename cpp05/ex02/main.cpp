/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:38:51 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/21 12:02:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	*b = new Bureaucrat("Bender", 1);
	PresidentialPardonForm	*ppf = new PresidentialPardonForm("Bender");

	std::cout << *ppf;
	std::cout << *b;
	b->signForm(*ppf);
	b->executeForm(*ppf);

	delete b;
	delete ppf;
}