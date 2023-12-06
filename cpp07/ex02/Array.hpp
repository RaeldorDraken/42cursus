/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:49:35 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/06 19:25:42 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	public:
		Array(void) : _array(NULL), _len(0) {}
		Array(unsigned int n) : _array(new T[n]), _len(n) {}
		Array(Array const &src) : _array(NULL), _len(0) {*this = src;}
		~Array(void) {delete [] _array;}

		Array	&operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete [] _array;
				_len = rhs._len;
				_array = new T[_len];
				for (unsigned int i = 0; i < _len; i++)
					_array[i] = rhs._array[i];
			}
			return (*this);
		}

		T	&operator[](unsigned int i)
		{
			if (i >= _len)
				throw std::exception();
			return (_array[i]);
		}

		unsigned int	size(void) const 
		{
			return (_len);
		}

	private:
		T				*_array;
		unsigned int	_len;
};

#endif