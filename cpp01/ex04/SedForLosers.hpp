/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SedForLosers.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:00:16 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/09 11:13:18 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDFORLOSERS_HPP
# define SEDFORLOSERS_HPP

#include <iostream>
#include <fstream>
#include <string>

class StringReplace
{
	public:
		StringReplace();
		~StringReplace();
		int	find_replace(std::string filename, std::string s1, std::string s2);

	private:
		std::string	_filename;
		std::string	_outfilename;
		std::string	_s1;
		std::string	_s2;
		std::string _tempfile;
		std::string line;
		void	set_internal_vars(std::string filename, std::string s1, std::string s2);
		void	replaceString();
};

#endif