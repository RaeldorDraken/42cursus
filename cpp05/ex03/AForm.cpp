/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:34:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/22 09:43:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	return ;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
	if (gradeSign < 1 || gradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeSign > 150 || gradeExec > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(AForm const &src) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec)
{
	*this = src;
	return ;
}

AForm::~AForm(void)
{
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

std::string const	AForm::getName(void) const
{
	return (this->_name);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_gradeExec);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
	return ;
}

const void	AForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->_gradeExec)
		throw AForm::GradeTooLowException();
	else if (!this->_signed)
		throw AForm::FormNotSignedException();
	else
		this->action();
	return ;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream	&operator<<(std::ostream &o, AForm const &rhs)
{
	o << rhs.getName() << " form, grade to sign: " << rhs.getGradeSign() << ", grade to execute: " << rhs.getGradeExec() << ", signed: " << rhs.getSigned() << std::endl;
	return (o);
}