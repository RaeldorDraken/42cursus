/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:13:20 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/23 19:39:47 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_HPP
# define HumanB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string _name);
		~HumanB(void);
		void attack(void);
		void setName(std::string _name);
		void setWeapon(Weapon &_weapon);
		std::string getName(void);
		Weapon getWeapon(void);
	private:
		std::string name;
		Weapon *weapon;
};

#endif