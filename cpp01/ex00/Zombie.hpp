/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:45:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/09 20:34:37 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie 
{
	public:
		Zombie(std::string _name);
		~Zombie(void);
		void announce(void);
	private:
		std::string	name;
};

Zombie* newZombie(std::string name);
void 	randomChump(std::string name);

#endif