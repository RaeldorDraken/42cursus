/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:17:18 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 11:49:04 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include<iostream>
# include<string>
# include"ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string	_type;
		bool	_isEquiped;
	public:
		AMateria(void );
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);

		AMateria &operator=(AMateria const & rhs);
		
		std::string const &getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		bool getIsEquiped(void) const;
		void setIsEquiped(bool equip);
};

#endif