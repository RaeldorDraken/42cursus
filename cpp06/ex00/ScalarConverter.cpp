/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:48 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/29 18:52:21 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

bool	ScalarConverter::isChar(std::string input)
{
	if (input.length() == 1 && !isdigit(input[0]))
		return (true);
	return (false);
}

bool	ScalarConverter::isInt(std::string input)
{
	if (input.length() == 1 && isdigit(input[0]))
		return (true);
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloat(std::string input)
{
	if (input[input.length() - 1] == 'f')
		input.erase(input.length() - 1);
	else
		return (false);
	if (input.length() == 2 && isdigit(input[0]) && input[1] == 'f')
		return (true);
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]) && input[i] != '.')
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isDouble(std::string input)
{
	if (input.length() == 1 && isdigit(input[0]))
		return (true);
	if (input.length() > 1 && (isdigit(input[0]) || input[0] == '-'))
	{
		for (size_t i = 1; i < input.length(); i++)
		{
			if (!isdigit(input[i]) && input[i] != '.')
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isInf(std::string input)
{
	if (input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
		return (true);
	return (false);
}

bool	ScalarConverter::isInff(std::string input)
{
	if (input == "inff" || input == "+inff" || input == "-inff" || input == "nanf" )
		return (true);
	return (false);
}

void	ScalarConverter::printChar(char c)
{
	if (isprint(c))
	{
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(c) << std::endl;
		std::cout << "cast float: " << std::fixed << std::setprecision(2) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "cast double: " << std::fixed <<std::setprecision(2) << static_cast<double>(c) << std::endl;
	}
	else
		std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(long int n)
{
	if (n > std::numeric_limits<int>::max() 
	|| n < std::numeric_limits<int>::min())
		std::cout << "int: Out of range" << std::endl;
	else
	{
    	std::cout << "int: " << n << std::endl;
		std::cout << "cast char: '" << static_cast<char>(n) << "'" << std::endl;
		std::cout << "cast float: " << std::fixed << std::setprecision(2) << static_cast<float>(n) << "f" << std::endl;
		std::cout << "cast double: " << std::fixed << std::setprecision(2) << static_cast<double>(n) << std::endl;
	}
}

void ScalarConverter::printFloat(float f)
{
    if (std::abs(f) > std::numeric_limits<float>::max())
	        std::cout << "float: Out of range" << std::endl;
    else
	{
        std::cout << "float: " << f << "f" << std::endl;
		std::cout << "cast char: '" << static_cast<char>(f) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(f) << std::endl;
		std::cout << "cast double: " << std::fixed << std::setprecision(2) << static_cast<double>(f) << std::endl;
	}
}

void ScalarConverter::printDouble(double d)
{
    if (std::abs(d) > std::numeric_limits<double>::max())
        std::cout << "double: Out of range" << std::endl;
    else
	{
        std::cout << "double: " << d << std::endl;
		std::cout << "cast char: '" << static_cast<char>(d) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(d) << std::endl;
		std::cout << "cast float: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << "f" << std::endl;
	}
}

void	ScalarConverter::printInff(std::string input)
{
	if (input == "inff" || input == "+inff")
	{
		std::cout << "float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
		std::cout << "cast char: '" << static_cast<char>(std::numeric_limits<float>::infinity()) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(std::numeric_limits<float>::infinity()) << std::endl;
		std::cout << "cast double: " << std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (input == "-inff")
	{
		std::cout << "float: " << -std::numeric_limits<float>::infinity() << std::endl;
		std::cout << "cast char: '" << static_cast<char>(-std::numeric_limits<float>::infinity()) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(-std::numeric_limits<float>::infinity()) << std::endl;
		std::cout << "cast double: " << -std::numeric_limits<double>::infinity() << std::endl;
	}
	else if (input == "nanf")
	{
		std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
		std::cout << "cast char: '" << static_cast<char>(std::numeric_limits<float>::quiet_NaN()) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(std::numeric_limits<float>::quiet_NaN()) << std::endl;
		std::cout << "cast double: " << static_cast<double>(std::numeric_limits<float>::quiet_NaN()) << std::endl;
	}
}

void	ScalarConverter::printInf(std::string input)
{
	if (input == "inf" || input == "+inf")
	{
		std::cout << "double: " << std::numeric_limits<double>::infinity() << std::endl;
		std::cout << "cast char: '" << static_cast<char>(std::numeric_limits<double>::infinity()) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(std::numeric_limits<double>::infinity()) << std::endl;
		std::cout << "cast float: " << std::numeric_limits<float>::infinity() << "f" << std::endl;
	}
	else if (input == "-inf")
	{
		std::cout << "double: " << -std::numeric_limits<double>::infinity() << std::endl;
		std::cout << "cast char: '" << static_cast<char>(-std::numeric_limits<double>::infinity()) << "'" << std::endl;
		std::cout << "cast int: " << static_cast<int>(-std::numeric_limits<double>::infinity()) << std::endl;
		std::cout << "cast float: " << -std::numeric_limits<float>::infinity() << "f" << std::endl;
	}
	else if (input == "nan")
	{
		std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
   		std::cout << "cast char: '" << static_cast<char>(std::numeric_limits<double>::quiet_NaN()) << "'" << std::endl;
	    std::cout << "cast int: " << static_cast<int>(std::numeric_limits<double>::quiet_NaN()) << std::endl;
	    std::cout << "cast float: " << static_cast<float>(std::numeric_limits<double>::quiet_NaN()) << "f" << std::endl;
	}
}

void	ScalarConverter::convert(std::string input)
{
	if (isInf(input))
		printInf(input);
	else if (isInff(input))
		printInff(input);
	else if (isChar(input))
		printChar(input[0]);
	else if (isInt(input))
		printInt(atol(input.c_str()));
	else if (isFloat(input))
		printFloat(atof(input.c_str()));
	else if (isDouble(input))
		printDouble(strtod(input.c_str(), NULL));
	else
		std::cout << "impossible" << std::endl;
}