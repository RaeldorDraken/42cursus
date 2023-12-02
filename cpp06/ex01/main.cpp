/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:20 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/02 16:31:59 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data;
	Data *data2;

	int n = 42;
	uintptr_t raw;

	data = new Data;
	data->c = n;
	data->n = n;
	data->p = &n;

	std::cout << "Data before: " << data << std::endl;
	std::cout << "\tchar: " << data->c << std::endl;
	std::cout << "\tint: " << data->n << std::endl;
	std::cout << "\tint*: " << data->p << std::endl;

	raw = Serializer::serialize(data);

	std::cout << std::endl << "Raw data: " << raw << std::endl << std::endl;

	data2 = Serializer::deserialize(raw);

	std::cout << "Data after: " << data2 << std::endl;
	std::cout << "\tchar: " << data2->c << std::endl;
	std::cout << "\tint: " << data2->n << std::endl;
	std::cout << "\tint*: " << data2->p << std::endl;

	return (0);
}