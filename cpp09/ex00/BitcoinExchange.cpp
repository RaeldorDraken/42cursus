/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:26 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/19 10:20:49 by eros-gir         ###   ########.fr       */
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
        std::string error = "BTC file ";
        error.append(fd);
        error.append(" could not be opened.");
        throw std::runtime_error(error);
        return true;
    }

    float fvalue = 0;
    std::string line;
    int linecount = 0;

    while (std::getline(file, line))
    {
        std::istringstream linestream(line);
        std::string date;
        std::string value;

        if (std::getline(linestream, date, '|') && std::getline(linestream, value))
        {
            try
            {
                date = date.substr(0, 10);
                try
                {
                    value = value.substr(1, value.length());
                    for (int i = 0; i < static_cast<int>(value.length()); i++)
                        if (!std::isdigit(value[i]) && value[i] != '.' && value[i] != '-')
                            throw std::invalid_argument("Error: invalid number");
                    fvalue = std::atof(value.c_str());
                }
                catch (const std::exception &e)
                {
                    throw std::invalid_argument("Error: invalid number.");
                    return true;
                }

                parseDate(date);

                if (data.find(date) != data.end())
                {
                    std::map<std::string, float>::const_iterator it = data.lower_bound(date);
                    if (it == data.begin() || (it != data.end() && it->first != date))
                        --it;

                    std::cout << date << " => " << fvalue << " = " << it->second * fvalue << std::endl;
                }
            }
            catch (const std::exception &e)
            {
                if (linecount > 0)
                    std::cout << e.what() << std::endl;
            }
            linecount++;
        }
        else
        {
            std::cout << "Error: date " << line << " is invalid." << std::endl;
        }
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