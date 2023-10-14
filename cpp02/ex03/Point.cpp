/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:39:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/14 18:36:46 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Constructors and destructor

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

//Operators

Point &Point::operator=(const Point &rhs)
{
	const float tmpx = rhs.getX();
	const float tmpy = rhs.getY();

	this->setX(tmpx);
	this->setY(tmpy);
	return (*this);
}

//Getters and setters

void	Point::setX(const float x)
{
	this->_x.setRawBits(x);
}

void	Point::setY(const float y)
{
	this->_y = y;
}

float	Point::getX() const
{
	return (this->_x);
}

float	Point::getY() const
{
	return (this->_y);
}

Fixed	Point::getFixedX() const
{
	return (this->_x);
}

Fixed	Point::getFixedY() const
{
	return (this->_y);
}