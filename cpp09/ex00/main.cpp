/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:08 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/19 09:41:01 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin <input_file>" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange::btc(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}