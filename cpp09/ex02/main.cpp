/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:56:33 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/14 19:09:55 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "Usage: ./PmergeMe 1 2 3 4 5 6 7 8 9 10" << std::endl;
        return 1;
    }

    try
    {
        std::vector<std::string> arguments(argv + 1, argv + argc);
        PmergeMe::mergeMe(arguments.data(), arguments.size());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}