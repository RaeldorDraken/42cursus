/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:28:07 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 21:04:49 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &src);
		~DiamondTrap(void);
		DiamondTrap	&operator=(DiamondTrap const &rhs);
		void	whoAmI(void);

		int		getHP(void) const;
		int		getEP(void) const;
		int		getAtk(void) const;
		std::string	getName(void) const;

		void	setHP(int hp);
		void	setEP(int ep);
		void	setAtk(int atk);
		void	setName(std::string name);
};

#endif
