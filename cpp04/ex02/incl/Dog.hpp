/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:54:19 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 09:32:03 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain	*_brain;
	public:
		Dog();
		Dog(Dog const &src);
		~Dog();

		Dog &operator=(Dog const &rhs);

		void	makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif