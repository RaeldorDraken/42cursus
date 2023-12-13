/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:19:42 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:29:45 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int		main(void)
{
	//Subject Test
	std::cout << "------------------------" << std::endl;
	std::cout << "------Subject Test------" << std::endl;
	std::cout << "------------------------" << std::endl;
	Span sp = Span(5);
	
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "------------------------" << std::endl;

	//10000 random numbers
	
	std::cout << "------------------------" << std::endl;
	std::cout << "-----10000 num test-----" << std::endl;
	std::cout << "------------------------" << std::endl;

	srand(time(NULL)+rand());
	Span sp2 = Span(10000);
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(rand() % 90000);
		
	sp2.addNumber(v.begin(), v.end());

	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	std::cout << "------------------------" << std::endl;

	return (0);
}