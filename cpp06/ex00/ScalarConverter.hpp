/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/26 16:51:24 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	public:
		static void	convert(std::string input);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter	&operator=(ScalarConverter const &rhs);

		static bool	isChar(std::string input);
		static bool	isInt(std::string input);
		static bool	isFloat(std::string input);
		static bool	isDouble(std::string input);
		static bool	isInf(std::string input);
		static bool	isInff(std::string input);

		static void	printChar(char c);
		static void	printInt(long int n);
		static void	printFloat(float f);
		static void	printDouble(double d);
		static void	printInf(std::string input);
		static void	printInff(std::string input);
};

#endif