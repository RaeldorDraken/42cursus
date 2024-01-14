/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:17 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/14 19:10:08 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return;
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
	return;
}

PmergeMe::~PmergeMe(void)
{
	return;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	return *this;
}

void	PmergeMe::printDeque(std::deque<int> const &deq)
{
	std::cout << "Deque: ";
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::printVector(std::vector<int> const &vec)
{
	std::cout << "Vector: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::mergeAuxVector(std::vector<int> &vec, int start, int mid, int end)
{
	std::vector<int>	left;
	std::vector<int>	right;
	int					i;
	int					j;
	int					k;

	for (i = 0; i < mid - start + 1; i++)
		left.push_back(vec[start + i]);
	for (j = 0; j < end - mid; j++)
		right.push_back(vec[mid + 1 + j]);
	i = 0;
	j = 0;
	k = start;
	while (i < mid - start + 1 && j < end - mid)
	{
		if (left[i] <= right[j])
			vec[k++] = left[i++];
		else
			vec[k++] = right[j++];
	}
	while (i < mid - start + 1)
		vec[k++] = left[i++];
	while (j < end - mid)
		vec[k++] = right[j++];
}

void	PmergeMe::mergeSortVector(std::vector<int> &vec, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		mergeSortVector(vec, start, mid);
		mergeSortVector(vec, mid + 1, end);
		mergeAuxVector(vec, start, mid, end);
	}
}

void	PmergeMe::mergeAuxDeque(std::deque<int> &deq, int start, int mid, int end)
{
	std::deque<int>	left;
	std::deque<int>	right;
	int					i;
	int					j;
	int					k;

	for (i = 0; i < mid - start + 1; i++)
		left.push_back(deq[start + i]);
	for (j = 0; j < end - mid; j++)
		right.push_back(deq[mid + 1 + j]);
	i = 0;
	j = 0;
	k = start;
	while (i < mid - start + 1 && j < end - mid)
	{
		if (left[i] <= right[j])
			deq[k++] = left[i++];
		else
			deq[k++] = right[j++];
	}
	while (i < mid - start + 1)
		deq[k++] = left[i++];
	while (j < end - mid)
		deq[k++] = right[j++];
}

void	PmergeMe::mergeSortDeque(std::deque<int> &deq, int start, int end)
{
	int	mid;

	if (start < end)
	{
		mid = start + (end - start) / 2;
		mergeSortDeque(deq, start, mid);
		mergeSortDeque(deq, mid + 1, end);
		mergeAuxDeque(deq, start, mid, end);
	}
}

void PmergeMe::mergeMe(const std::string* argv, size_t argc)
{
	std::vector<int> vec;
	std::deque<int> deq;
	int nb;
	size_t i;

	for (i = 0; i < argc; i++)
	{
		nb = std::atoi(argv[i].c_str());
		vec.push_back(nb);
		deq.push_back(nb);
	}

	std::cout << "Before sorting:" << std::endl;
	printVector(vec);
	printDeque(deq);
	std::cout << std::endl;

	try
	{
		std::clock_t start = std::clock();

		mergeSortVector(vec, 0, vec.size() - 1);
		std::cout << "After sorting:" << std::endl;
		printVector(vec);

		std::clock_t end = std::clock();

		double vectorTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;

		start = std::clock();

		mergeSortDeque(deq, 0, deq.size() - 1);
		printDeque(deq);
		std::cout << std::endl;

		end = std::clock();
		//print timers
        std::cout << std::fixed << std::setprecision(8);
		std::cout << "Time elapsed processing " << argc << " elements: " << std::endl;
        std::cout << "Vector: " << vectorTime << "s" << std::endl;
		double dequeTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Deque: " << dequeTime << "s" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}