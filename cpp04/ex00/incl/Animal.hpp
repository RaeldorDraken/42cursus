/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:48 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/23 11:18:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &src);
		virtual ~Animal();

		Animal &operator=(Animal const &rhs);

		std::string		getType(void) const;
		void			setType(std::string type);

		virtual void	makeSound(void) const;
};

std::ostream &operator<<(std::ostream &out, Animal const &rhs);

#endif