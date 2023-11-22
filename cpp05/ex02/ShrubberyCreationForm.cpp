/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:47:36 by eros-gir          #+#    #+#             */
/*   Updated: 2023/11/22 09:48:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

std::string		ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
	return ;
}

void ShrubberyCreationForm::action() const
{
    std::ofstream ofs((_target + "_shrubbery").c_str());

    if (ofs.is_open()) {
        ofs << "	         \",.,\"\n"
               "        \"MMMM_    ,..,\"\n"
               "          \"\\\"_ \\\"__\\\"MMMMM          ,...,,\"\n"
               "   \",..., __.\" --\"    ,.,     _-\"MMMMMMM\"\n"
               "  \"MMMMMM\"___ \"_._   MMM\"_.\"\" _ \"\"\"\"\"\"\n"
               "   \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n"
               "          \",., _\"__ \\__./ .\"\n"
               "         \"MMMMM_\"  \"_    ./\"\n"
               "          \"\'\'\'\'      (    )\"\n"
               "   \"\"._______________.-\'____\"---._.\"\n"
               "    \"\\                          /\"\n"
               "     \"\\________________________/\"\n"
               "     \"(_)                    (_)\""
            << std::endl;
        ofs.close();

        std::cout << "ASCII art has been written to " << _target << "_shrubbery" << std::endl;
    } 
	else
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
}