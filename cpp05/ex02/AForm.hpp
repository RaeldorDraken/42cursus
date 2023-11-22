/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 23:30:02 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/20 23:37:38 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm		&operator=(AForm const &rhs);

		std::string const	getName(void) const;
		int					getGradeSign(void) const;
		int					getGradeExec(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const &bureaucrat);
		const void			execute(Bureaucrat const &executor) const;
		virtual void		action(void) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;
};

std::ostream	&operator<<(std::ostream &o, AForm const &rhs);

#endif
