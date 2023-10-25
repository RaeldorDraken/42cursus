/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:48 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 10:04:38 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include"polymorph.h"
# include"Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const &src);
	public:
		virtual ~AAnimal();

		AAnimal &operator=(AAnimal const &rhs);

		std::string		getType(void) const;
		void			setType(std::string type);

		virtual void	makeSound(void) const;
		virtual Brain	*getBrain(void) const = 0;
};

std::ostream &operator<<(std::ostream &out, AAnimal const &rhs);

#endif