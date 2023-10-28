/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:45:15 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/28 17:10:50 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include<iostream>
# include<iomanip>
# include"AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const & src);
		virtual ~Ice(void);

		Ice &operator=(Ice const & rhs);

		virtual AMateria*	clone(void) const;
		virtual void		use(ICharacter& target);
};

#endif