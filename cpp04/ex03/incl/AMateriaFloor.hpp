/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaFloor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:55:00 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/29 21:47:43 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIAFLOOR_HPP
# define AMATERIAFLOOR_HPP

# include<iostream>
# include<iomanip>
# include"AMateria.hpp"

class AMateriaFloor
{
	private:
		AMateriaFloor	*_next;
		AMateriaFloor	*_prev;
		AMateria		*_materia;
	public:
		AMateriaFloor(void);
		AMateriaFloor(AMateria *materia);
		AMateriaFloor(AMateriaFloor const & src);
		~AMateriaFloor(void);

		AMateriaFloor	&operator=(AMateriaFloor const &rhs);

		AMateriaFloor	*getNext(void) const;
		AMateriaFloor	*getPrev(void) const;
		AMateria		*getMateria(void) const;

		void			setNext(AMateriaFloor *next);
		void			setPrev(AMateriaFloor *prev);
};

#endif