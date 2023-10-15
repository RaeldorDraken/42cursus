/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/15 17:38:41 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Constructors and destructor

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &src) : _x(src.getX()), _y(src.getY())
{
	*this = src;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

//Operators

Point &Point::operator=(const Point &rfs)
{
	(void)rfs;
	return (*this);
}

//Getters and setters

Fixed const	&Point::getX() const
{
	return (_x);
}

Fixed const	&Point::getY() const
{
	return (_y);
}

//Non Member functions

std::ostream &operator<<(std::ostream &output, const Point &rhs)
{
	output << "Point(" << rhs.getX() << ", " << rhs.getY() << ")";
	return (output);
}