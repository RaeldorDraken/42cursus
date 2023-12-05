/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:18:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/05 09:46:38 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int int_array[5] = {1, 2, 3, 4, 5};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};
	float float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	std::cout << "----Test Int----" << std::endl;
	iter(int_array, 5, print);
	std::cout << std::endl;

	std::cout << "----Test String----" << std::endl;
	iter(string_array, 5, print);
	std::cout << std::endl;

	std::cout << "----Test Float----" << std::endl;
	iter(float_array, 5, print);
	std::cout << std::endl;

	return (0);
}