/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:40:20 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/01 11:33:27 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	identify(&p);
}

int main(void)
{
	std::cout << "Test 1" << std::endl;
	std::cout << "randomize seed" << std::endl;
	srand(time(NULL));
	Base *p = generate();
	identify(p);
	identify(*p);
	std::cout << std::endl;

	std::cout << "Test 2" << std::endl;
	std::cout << "randomize seed" << std::endl;
	srand(time(NULL) + time(NULL));
	Base *p2 = generate();
	identify(p2);
	identify(*p2);
	std::cout << std::endl;

	std::cout << "Test 3" << std::endl;
	std::cout << "randomize seed" << std::endl;
	srand(time(NULL) + time(NULL) + time(NULL));
	Base *p3 = generate();
	identify(p3);
	identify(*p3);
	std::cout << std::endl;

	delete p;
	delete p2;
	delete p3;
	return (0);
}