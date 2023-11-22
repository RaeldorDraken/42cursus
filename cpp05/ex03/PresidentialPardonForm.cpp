/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:49:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/22 09:45:33 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default", 25, 5), _target("default")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm("PresidentialPardonForm", 25, 5), _target(src._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	AForm::operator=(rhs);
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
	o << rhs.getName() << " form, grade required to sign it: " << rhs.getGradeSign() << ", grade required to execute it: " << rhs.getGradeExec() << ", is signed: " << rhs.getSigned() << std::endl;
	return (o);
}

std::string	PresidentialPardonForm::getTarget(void)
{
	return (this->_target);
}

void	PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
	return ;
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	return ;
}