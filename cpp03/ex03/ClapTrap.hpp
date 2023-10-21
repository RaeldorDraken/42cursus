/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 20:07:03 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/21 16:45:54 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

typedef enum e_type	{
	NONE,
	CLAPTRAP,
	SCAVTRAP,
	FRAGTRAP
}	t_type;

class ClapTrap
{
	protected:
		std::string	_name;
		int	_hp;
		int	_ep;
		int	_atk;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(int hp, int ep, int atk, std::string name);
		ClapTrap(ClapTrap const &src);
		~ClapTrap();
		ClapTrap &operator=(ClapTrap const &rhs);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int	getHp(void) const;
		int	getEp(void) const;
		int	getAtk(void) const;
		
		void	setName(std::string name);
		void	setHp(int hp);
		void	setEp(int ep);
		void	setAtk(int atk);
};