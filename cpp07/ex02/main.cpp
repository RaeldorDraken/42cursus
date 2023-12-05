/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:18:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/05 10:10:56 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int>	a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	try
	{
		a[5] = 5;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}