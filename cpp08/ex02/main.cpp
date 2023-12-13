/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 09:35:15 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/13 09:59:35 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{

	//Subject Test
	std::cout << "------------------------" << std::endl;
	std::cout << "------Subject Test------" << std::endl;
	std::cout << "------------------------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "MutantStack top: " << mstack.top() << std::endl;
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "poping top element..." << std::endl;
	mstack.pop();
	std::cout << "MutantStack top: " << mstack.top() << std::endl;
	
	std::cout << "MutantStack size: " << mstack.size() << std::endl << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "MutantStack size: " << mstack.size() << std::endl;
	std::cout << "------------------------\n" << std::endl;

	//normal stack test
	std::cout << "------------------------" << std::endl;
	std::cout << "-------Stack test-------" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::stack<int> s(mstack);

	std::cout << "Normal stack size: "<< s.size() << std::endl;
	int i = 0;
	while (s.size())
	{
		std::cout << s.top() << std::endl;
		i++;
		std::cout << "poping top element... times: " << i << std::endl;
		s.pop();
	}

	std::cout << "------------------------" << std::endl;
	return (0);
}