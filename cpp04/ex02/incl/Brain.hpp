/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:16:17 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/25 09:32:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include"polymorph.h"

class Brain 
{
	private:
		std::string		ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain	&operator=(Brain const &rhs);

		std::string	getIdea(int i) const;
		int			setIdea(int i, std::string idea);
};

#endif