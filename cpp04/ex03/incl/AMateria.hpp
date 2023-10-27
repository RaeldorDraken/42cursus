/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:17:18 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:30:35 by eros-gir         ###   ########.fr       */
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
		std::string	_trash;
	public:
		AMateria(void );
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);
		std::string const &getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		std::string const &getTrash(void) const;
};

#endif