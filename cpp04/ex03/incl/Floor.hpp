/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:52:00 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/28 17:10:34 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include<iostream>
# include<iomanip>
# include"AMateriaFloor.hpp"

class Floor
{
	private:
		AMateriaFloor	*_first;
		AMateriaFloor	*_last;
		int				_nbMateria;
	public:
		Floor(void);
		Floor(Floor const & src);
		~Floor(void);

		Floor &operator=(Floor const & rhs);

		void			addMateria(AMateria *materia);
		void			delMateria(AMateriaFloor *materia);
		void			eraseMateria(void);

		AMateriaFloor	*getFirst(void) const;
		AMateriaFloor	*getLast(void) const;
		int				getNbMateria(void) const;
		
		void			printFloor(void) const;
};

#endif