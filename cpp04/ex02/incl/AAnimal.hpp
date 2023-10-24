/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:53:48 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/24 22:59:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include"polymorph.h"

class AAnimal
{
	protected:
		std::string _type;
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const &src);
	public:
		virtual ~AAnimal();

		static AAnimal	&getInstance(void);

		AAnimal &operator=(AAnimal const &rhs);

		std::string		getType(void) const;
		void			setType(std::string type);

		virtual void	makeSound(void) const;
};

std::ostream &operator<<(std::ostream &out, AAnimal const &rhs);

#endif