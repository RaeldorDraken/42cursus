/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:01:46 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/09 11:13:40 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedForLosers.hpp"

StringReplace::StringReplace()
{
}

StringReplace::~StringReplace()
{
}

void	StringReplace::replaceString()
{
	size_t findLen = this->_s1.length();
	size_t contentLen = this->_tempfile.length();
	size_t i;
	std::string result("");
	i = 0;
	while (i < contentLen)
	{
		if (this->_tempfile.substr(i, findLen) == _s1)
		{
			result += _s2;
			i+= findLen;
		}
		else
		{
			result += this->_tempfile[i];
			i++;
		}
	}
	this->_tempfile = result;
}

void StringReplace::set_internal_vars(std::string filename, std::string s1, std::string s2)
{
	this->_filename = filename;
	this->_outfilename = filename + ".replace";
	this->_s1 = s1;
	this->_s2 = s2;
}

int	StringReplace::find_replace(std::string filename, std::string s1, std::string s2)
{
	set_internal_vars(filename, s1, s2);
	std::ifstream ifs(_filename.c_str());
	std::ofstream ofs(_outfilename.c_str());

	if (!ifs.is_open() || !ofs.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return (1);
	}
	while (std::getline(ifs, line))
		_tempfile += line + "\n";
	replaceString();
	ofs << _tempfile;
	ifs.close();
	ofs.close();
	return (0);
}