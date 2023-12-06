/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:18:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/06 19:44:17 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int>	a(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
    std::cout << "Array a:" << std::endl;
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

    std::cout << "Array b created from a" << std::endl;
    Array<int>	b;

    b = a;
    a[0] = 42;
    std::cout << "Array a modified:" << std::endl;
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << a[i] << std::endl;

    std::cout << "Array b:" << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << std::endl;

    // std::cout << "Array c constant" << std::endl;
    // Array<int> c;
    // c[] = {1, 2, 3, 4, 5};
    // std::cout << "Array c:" << std::endl;
    // for (unsigned int i = 0; i < c.size(); i++)
    //     std::cout << c[i] << std::endl;

    std::cout << "Array s" << std::endl;
    Array<std::string> s(5);
    s[0] = "Hello";
    s[1] = "World";
    s[2] = "!";
    s[3] = "I'm";
    s[4] = "a string";
    std::cout << "Array s:" << std::endl;
    for (unsigned int i = 0; i < s.size(); i++)
        std::cout << s[i] << " ";
    std::cout << std::endl;
    
	return (0);
}
/*
#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/