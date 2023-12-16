/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:38 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/16 18:23:57 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <map>


class	BitcoinExchange
{
	public:
		static void	btc(std::string fd);
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		static bool	getCSV(std::map<std::string, float> &data);
		static bool	getBTC(const std::map<std::string, float> &data, std::string fd);
		static void	parseDate(std::string &date);
};
#endif
