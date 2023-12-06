/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:18:14 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/06 16:13:02 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{

	std::cout <<"----Test Int----"<< std::endl;
	int a = 2;
	int b = 3;

	std::cout << "\ta = " << a << " b = " << b << std::endl;
	::swap(a, b);
	std::cout << "\ta = " << a << " b = " << b << std::endl;
	std::cout << "\tmin(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "\tmax(a, b) = " << ::max(a, b) << std::endl;

	std::cout << std::endl;

	char c1 = 'c';
	char c2 = 'd';

	std::cout <<"----Test Char----"<< std::endl;
	std::cout << "\tc1 = " << c1 << " c2 = " << c2 << std::endl;
	::swap(c1, c2);
	std::cout << "\tc1 = " << c1 << " c2 = " << c2 << std::endl;
	std::cout << "\tmin(c1, c2) = " << ::min(c1, c2) << std::endl;
	std::cout << "\tmax(c1, c2) = " << ::max(c1, c2) << std::endl;

	std::cout << std::endl;

	std::cout <<"----Test String----"<< std::endl;
	std::string s1 = "stringo1";
	std::string s2 = "stringo2";
	std::cout << "\ts1 = " << s1 << " s2 = " << s2 << std::endl;
	::swap(s1, s2);
	std::cout << "\ts1 = " << s1 << " s2 = " << s2 << std::endl;
	std::cout << "\tmin(s1, s2) = " << ::min(s1, s2) << std::endl;
	std::cout << "\tmax(s1, s2) = " << ::max(s1, s2) << std::endl;

	std::cout << std::endl;

	std::cout <<"----Test Float----"<< std::endl;
	float e = 2.2;
	float f = 3.3;

	std::cout << "\te = " << e << " f = " << f << std::endl;
	::swap(e, f);
	std::cout << "\te = " << e << " f = " << f << std::endl;
	std::cout << "\tmin(e, f) = " << ::min(e, f) << std::endl;
	std::cout << "\tmax(e, f) = " << ::max(e, f) << std::endl;

	std::cout << std::endl;

	return (0);
}
