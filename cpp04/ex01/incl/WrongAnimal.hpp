/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:57:49 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:27:19 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class	WrongAnimal
{
	protected:
		std::string	_type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal();

		WrongAnimal &operator=(WrongAnimal const &rhs);

		virtual void	makeSound(void) const;

		std::string	getType(void) const;
		void		setType(std::string type);
};

std::ostream &operator<<(std::ostream &out, WrongAnimal const &rhs);

#endif