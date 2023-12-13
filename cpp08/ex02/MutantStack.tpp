/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:36:28 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:41:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>()
{
	return ;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src) : std::stack<T>(src)
{
	return ;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	return ;
}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const & rhs)
{
	if (this != &rhs)
		this->c = rhs.c;
	return (*this);
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}
