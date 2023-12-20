/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/20 10:14:17 by eros-gir         ###   ########.fr       */
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
	size_t yearEnd = date.find('-');
	size_t monthEnd = date.find('-', yearEnd + 1);

	std::string year = date.substr(0, yearEnd);
	std::string month = date.substr(yearEnd + 1, monthEnd - yearEnd - 1);
	std::string day = date.substr(monthEnd + 1);

	date = year + month + day;
}

bool BitcoinExchange::getCSV(std::map<std::string, float> &data) 
{
	std::ifstream file("./data.csv");
	if (!file.is_open())
		throw std::runtime_error("CSV file not opened.");

	int linecount = 0;
	std::string line;

	while (std::getline(file, line))
	{
		std::istringstream linestream(line);
		std::string date;
		std::string value;

		if (std::getline(linestream, date, ',') && std::getline(linestream, value))
		{
			try
			{
				float fvalue = std::atof(value.c_str());
				parseDate(date);
				data[date] = fvalue;
			} 
			catch (const std::exception &e)
			{
				if (linecount > 0)
				{
					file.close();
					return true;
				}
			}
			linecount++;
		}
	}
	file.close();
	return false;
}

bool BitcoinExchange::getBTC(const std::map<std::string, float> &data, std::string fd) 
{
	std::ifstream file(fd.c_str());
	if (!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
		return true;
	}

	float fvalue = 0;
	std::string line;
	int linecount = 1;
	bool isFirstLine = true;
	std::string prevDate;

	while (std::getline(file, line))
	{
		if (isFirstLine)
		{
			isFirstLine = false;
			continue;
		}

		std::istringstream linestream(line);
		std::string date;
		std::string value;

		if (std::getline(linestream, date, '|') && std::getline(linestream, value))
		{
			try
			{
				date = date.substr(0, 10);
				value = value.substr(1);

				std::istringstream valueStream(value);
				valueStream >> fvalue;
				if (fvalue <= 0)
					throw std::invalid_argument("Error: not a positive number.");

				parseDate(date);

				std::map<std::string, float>::const_iterator it = data.lower_bound(date);

				if (it != data.begin())
				{
					--it;
					float result = fvalue * it->second;
					if (result > INT_MAX)
						throw std::invalid_argument("Error: Value too high.");
					else
						std::cout << date.substr(0, 4) << "-" << date.substr(4, 2) << "-" << date.substr(6, 2) << " => " << fvalue << " = " << result << std::endl;
				}
				else if (!prevDate.empty())
				{
					std::cout << date.substr(0, 4) << "-" << date.substr(4, 2) << "-" << date.substr(6, 2) << " => " << fvalue << " = " << data.at(prevDate) * fvalue << std::endl;
				}

				prevDate = date;
			}
			catch (const std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else
		{
			std::cout << "Error: bad input" << " => " << line << std::endl;
		}

		linecount++;
	}

	file.close();
	return false;
}

void BitcoinExchange::btc(std::string file) 
{
	std::map<std::string, float> data;

	if (getCSV(data))
		throw std::runtime_error("Error parsing CSV file.");

	if (getBTC(data, file))
		throw std::runtime_error("Error getting BTC value.");
}
