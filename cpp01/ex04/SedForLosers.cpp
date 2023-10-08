/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:01:46 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/08 19:53:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

StringReplace::StringReplace()
{
}

StringReplace::~StringReplace()
{
}

void StringReplace::set_internal_vars(std::string filename, std::string s1, std::string s2)
{
	this->_filename = filename;
	this->_s1 = s1;
	this->_s2 = s2;
}

int	StringReplace::find_replace(std::string filename, std::string s1, std::string s2)
{
	set_internal_vars(filename, s1, s2);
	std::ifstream ifs(_filename);
	std::ofstream ofs(_filename + ".replace");

	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
		_tempfile += line + "\n";
	ifs.close();
	ofs.close();
	return (0);
}