/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:35:27 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:41:24 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(MutantStack const &src);
		~MutantStack(void);
		MutantStack &operator=(MutantStack const & rhs);
		
		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void);
		iterator	end(void);
};

#include "MutantStack.tpp"

#endif