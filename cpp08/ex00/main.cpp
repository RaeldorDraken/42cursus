/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:54:13 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:17:25 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"easyfind.hpp"
#include<vector>

int	main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	try
	{
		std::cout << easyfind(v, 3) << std::endl;
		std::cout << easyfind(v, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << ": Not found" << std::endl;
	}
	return (0);
}