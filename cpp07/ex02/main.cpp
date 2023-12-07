/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:18:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/07 10:41:00 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>
#include <string>

void	test1(const int MAX_VAL, Array<int> &numbers, int *mirror)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "---------------Copy tests---------------" << std::endl;
	Array<int> tmp = numbers;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "tmp Array '= operator' numbers Array" << std::endl;
	tmp[0] = 0;
	std::cout << "tmp[0] = " << tmp[0] << std::endl;
	std::cout << "numbers[0] = " << numbers[0] << std::endl;
	Array<int> test(tmp);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "test Array 'copy constructor' from tmp Array" << std::endl;
	test[0] = 42;
	std::cout << "test[0] = " << test[0] << std::endl;
	std::cout << "tmp[0] = " << tmp[0] << std::endl << std::endl;
}

int	test2(const int MAX_VAL, Array<int> &numbers, int *mirror)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "---------------Compare tests-------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	int tmp = 0;
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
		else
		{
		tmp = mirror[i] - numbers[i];
			std::cout << "numbers[" << i << "] = " << numbers[i] << 
			" | " << "mirror[" << i << "] = " << mirror[i] << 
			" | " << "diff: " << tmp << std::endl << std::endl;
		}
	}
	return 0;
}

void	test3(const int MAX_VAL, Array<int> &numbers, int *mirror)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "---------------Out of bounds tests------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	try
	{
		std::cout << "numbers[-2]" << std::endl;
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Out of bounds" << std::endl;
	}
	try
	{
		std::cout << "numbers[MAX_VAL]" << std::endl;
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << " Out of bounds" << std::endl;
	}
	std::cout << std::endl;
}

void test4(const int MAX_VAL)
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "---------------Other types tests--------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	Array<char> chars(MAX_VAL);
	std::cout << std::endl << "---------------char test----------------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		chars[i] = rand() % 26 + 65;
		std::cout << "chars[" << i << "] = " << chars[i] << std::endl;
	}
	Array<float> floats(MAX_VAL);
	std::cout << std::endl  << "---------------float test---------------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		floats[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		std::cout << "floats[" << i << "] = " << floats[i] << "f" << std::endl;
	}
	Array<double> doubles(MAX_VAL);
	std::cout << std::endl  << "---------------double test--------------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		doubles[i] = static_cast<double>(rand()) / static_cast<double>(RAND_MAX);
		std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;
	}
	Array<std::string> strings(MAX_VAL);
	std::cout << std::endl  << "---------------string test--------------" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		strings[i] = "string" + std::to_string(i);
		std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
	}
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./a.out <number>" << std::endl;
		std::cerr << "number: size of the array" << std::endl;
		return 1;
	}
	const int MAX_VAL = atoi(argv[1]);
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//Test about Array copy
	test1(MAX_VAL, numbers, mirror);
	//Test comparing stored data to the original
	if (test2(MAX_VAL, numbers, mirror))
		return 1;
	//Throw exception out of bounds
	test3(MAX_VAL, numbers, mirror);
	//Test with other types of variables
	test4(MAX_VAL);

	delete [] mirror;
	return 0;
}
