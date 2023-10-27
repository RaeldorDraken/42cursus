/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:07:55 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/27 11:09:16 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include<iostream>
# include<iomanip>
# include"IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_materia[4];
		int				_count;
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & rhs);

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif