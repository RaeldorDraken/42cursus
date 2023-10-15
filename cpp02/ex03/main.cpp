/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:10:45 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/15 17:41:29 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point const a(Fixed(0), Fixed(0));
	Point const b(Fixed(10), Fixed(0));
	Point const c(Fixed(0), Fixed(10));

	const Point point(Fixed(5), Fixed(5));

	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << "point: " << point << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "point is inside the triangle" << std::endl;
	else
		std::cout << "point is outside the triangle" << std::endl;
	return 0;
}