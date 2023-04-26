/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   agenda.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:30:57 by eros-gir          #+#    #+#             */
/*   Updated: 2023/04/26 11:42:10 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"agenda.h"
#include"agenda.class.hpp"

int	main(void)
{
	char 	buff[512];
	Test	instance;
	std::cout << "agenda:" << std::endl;
	std::cin >> buff;
	std::cout << "You entered : [" << buff << "]" << std::endl;
	
	return(0);
}