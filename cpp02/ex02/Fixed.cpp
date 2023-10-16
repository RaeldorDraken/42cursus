/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:11:22 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/16 11:50:55 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors and destructor

Fixed::Fixed() : _fixed_point_value(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const float value)
{
	this->_fixed_point_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::Fixed(const int value)
{
	this->_fixed_point_value = value << this->_fractional_bits;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
		this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

//Comparators

bool Fixed::operator>(const Fixed &rhs)
{
	return (this->_fixed_point_value > rhs.getRawBits());
}

bool Fixed::operator<(const Fixed &rhs)
{
	return (this->_fixed_point_value < rhs.getRawBits());
}

bool Fixed::operator>=(const Fixed &rhs)
{
	return (this->_fixed_point_value >= rhs.getRawBits());
}

bool Fixed::operator<=(const Fixed &rhs)
{
	return (this->_fixed_point_value <= rhs.getRawBits());
}

bool Fixed::operator==(const Fixed &rhs)
{
	return (this->_fixed_point_value == rhs.getRawBits());
}

bool Fixed::operator!=(const Fixed &rhs)
{
	return (this->_fixed_point_value != rhs.getRawBits());
}

//Operators

Fixed Fixed::operator+(const Fixed &rhs)
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(const Fixed &rhs)
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed Fixed::operator++(void)
{
	this->_fixed_point_value++;
	return (*this);
}

Fixed Fixed::operator--(void)
{
	this->_fixed_point_value--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

//Min and max

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
	Fixed tmp(a);
	Fixed tmp2(b);

	if (tmp < tmp2)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
	Fixed tmp(a);
	Fixed tmp2(b);

	if (tmp > tmp2)
		return (a);
	return (b);
}

//Getters and setters

int		Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_fixed_point_value / (float)(1 << this->_fractional_bits));
}

int		Fixed::toInt(void) const
{
	int result;
	
	if (this->_fixed_point_value >= 0)
		result = (this->_fixed_point_value >> _fractional_bits);
	else
    	result = (this->_fixed_point_value >> _fractional_bits) + 1;
    return result;
}

std::ostream &operator<<(std::ostream &output, const Fixed &rhs)
{
	output << rhs.toFloat();
	return (output);
}