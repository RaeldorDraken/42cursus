/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:32:16 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/26 12:20:26 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AGENDA_CLASS_HPP
# define AGENDA_CLASS_HPP

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	ADD(void);
		void	SEARCH(void);
		void	EXIT(void);
	private:
		int	_index;
};

class Test
{
	public:
		Test(void);
		~Test(void);
};
#endif