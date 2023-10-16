/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:11:22 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/16 11:45:30 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point_value = roundf(value * (1 << this->_fractional_bits));
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point_value = value << this->_fractional_bits;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed_point_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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