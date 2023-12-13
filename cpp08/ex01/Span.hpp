/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:19:52 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:21:36 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <climits>

class Span {
	private:
		unsigned int		_n;
		std::vector<int>	_v;
		Span(void);
	public:
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);
		Span & operator=(Span const & rhs);

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		std::vector<int>	getV(void) const;
		unsigned int	getN(void) const;
		
		class	FullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif