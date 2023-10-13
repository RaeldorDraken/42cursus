/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:46:03 by eros-gir          #+#    #+#             */
/*   Updated: 2023/10/13 20:54:24 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "str: " << &str << std::endl;
	std::cout << "ptr: " << &ptr << std::endl;
	std::cout << "ref: " << &ref << std::endl;
	std::cout << "str: " << str << std::endl;
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "ref: " << ref << std::endl;
	return (0);
}