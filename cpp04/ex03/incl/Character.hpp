/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 10:59:53 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:27:20 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include<iostream>
# include<iomanip>
# include"AMateria.hpp"
# include"ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		int			_nbMateria;
	public:
		Character(void);
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character( void );

		Character &	operator=(Character const & rhs);

		virtual std::string const &	getName(void) const;
		virtual void				equip (AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

		//testing functions
		virtual void	printMaterias(void);
		virtual void	printTrash(void);
};

#endif