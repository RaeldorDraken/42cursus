/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/17 21:49:57 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	(void)rhs;
	return (*this);
}

void BitcoinExchange::parseDate(std::string &date) 
{
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	date = year + month + day;
}

bool BitcoinExchange::getCSV(std::map<std::string, float> &data) 
{
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw std::runtime_error("CSV file not opened.");

	int linecount = 0;
	std::string line;

	while (std::getline(file, line)) {
		std::istringstream linestream(line);
		std::string date;
		std::string value;

		if (std::getline(linestream, date, ',') && std::getline(linestream, value)) {
			try {
				std::istringstream valueStream(value);
				float fvalue;
				if (!(valueStream >> fvalue)) {
					std::cerr << "Error converting string to float\n";
					return true;
				}
				parseDate(date);
				data[date] = fvalue;
			} catch (const std::exception &e) {
				if (linecount > 0)
					return true;
			}
			linecount++;
		}
	}

	return false;
}

bool BitcoinExchange::getBTC(const std::map<std::string, float> &data, std::string fd) 
{
	std::string date = fd.substr(0, 8);
	std::string time = fd.substr(8, 4);

	if (data.find(date) == data.end()) {
		std::cerr << "Date not found\n";
		return true;
	}

	std::cout << std::fixed << std::setprecision(2) << data.at(date) << " at " << time << std::endl;
	return false;
}

void BitcoinExchange::btc(std::string fd) 
{
	std::map<std::string, float> data;

	if (getCSV(data))
		throw std::runtime_error("Error parsing CSV file.");

	if (getBTC(data, fd))
		throw std::runtime_error("Error getting BTC value.");
}