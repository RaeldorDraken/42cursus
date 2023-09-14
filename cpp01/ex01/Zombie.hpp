/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:45:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/09/09 20:59:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie 
{
	public:
		Zombie();
		Zombie(std::string _name);
		~Zombie(void);
		void			announce(void);
		int				setName(std::string _name);
		std::string		getName(void);
	private:
		std::string	name;
};

Zombie* zombieHorde(int N, std::string name);

#endif