/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:01:46 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/07 18:23:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

int	find_replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream ifs(filename);
	std::ofstream ofs(filename + ".replace");
	std::string line;

	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
	{
		size_t pos = 0;
		size_t found = line.find(s1);
		while (found != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			pos = found;
			found = line.find(s1, pos);
		}
		ofs << line << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}