/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:46:40 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 11:40:06 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include<iostream>
# include<iomanip>
# include"AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(void);
		Cure(Cure const & src);
		virtual ~Cure(void);

		Cure &operator=(Cure const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif