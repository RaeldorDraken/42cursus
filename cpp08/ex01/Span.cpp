/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:25:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:26:48 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
	return ;
}

Span::Span(Span const &src)
{
	*this = src;
	return ;
}

Span::~Span(void)
{
	return ;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->_n = rhs.getN();
		this->_v = rhs.getV();
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_v.size() < this->_n)
		this->_v.push_back(n);
	else
		throw Span::FullException();
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_v.size() + std::distance(begin, end) <= this->_n)
		this->_v.insert(this->_v.end(), begin, end);
	else
		throw Span::FullException();
}

unsigned int	Span::shortestSpan(void)
{
	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	std::sort(this->_v.begin(), this->_v.end());
	unsigned int	span = UINT_MAX;
	for (unsigned int i = 0; i < this->_v.size() - 1; i++)
	{
		if (static_cast<unsigned int>(this->_v[i + 1] - this->_v[i]) < span)
			span = static_cast<unsigned int>(this->_v[i + 1] - this->_v[i]);
	}
	return (span);
}

unsigned int	Span::longestSpan(void)
{
	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	std::sort(this->_v.begin(), this->_v.end());
	return (static_cast<unsigned int>(this->_v[this->_v.size() - 1] - this->_v[0]));
}

std::vector<int>	Span::getV(void) const
{
	return (this->_v);
}

unsigned int	Span::getN(void) const
{
	return (this->_n);
}

const char* Span::FullException::what() const throw()
{
	return ("Span is full");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}
