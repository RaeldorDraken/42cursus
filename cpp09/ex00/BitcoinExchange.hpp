/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 10:11:38 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 19:13:46 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iomanip>
# include <map>
# include <climits>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <iomanip>


class	BitcoinExchange
{
	public:
		static void	btc(std::string file);
	private:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		static bool	getCSV(std::map<std::string, float> &data);
		static bool	getBTC(const std::map<std::string, float> &data, std::string fd);
		static bool	parseDate(std::string &date);
};
#endif
