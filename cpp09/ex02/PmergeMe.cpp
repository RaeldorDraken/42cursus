/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:17 by eros-gir          #+#    #+#             */
/*   Updated: 2023/12/23 20:09:20 by eros-gir         ###   ########.fr       */
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

void	PmergeMe::checkRepeat(std::vector<int> const &vec)
{
	std::unordered_set<int>	set;
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (set.find(*it) != set.end())
			throw std::invalid_argument("Repeated numbers!");
		set.insert(*it);
	}
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

void PmergeMe::mergeMe(const std::string* argv)
{
    std::vector<int> vec;
    std::deque<int> deq;
    int nb;
    int i;

    for (i = 1; i < 100000; i++)
    {
        nb = std::stoi(argv[i]);
        vec.push_back(nb);
        deq.push_back(nb);
    }

    try
    {
        checkRepeat(vec);

        typedef std::chrono::high_resolution_clock Clock;

        Clock::time_point start = Clock::now();
        mergeSortVector(vec, 0, vec.size() - 1);
        Clock::time_point end = Clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Vector: " << elapsed.count() << "s" << std::endl;

        start = Clock::now();
        mergeSortDeque(deq, 0, deq.size() - 1);
        end = Clock::now();
        elapsed = end - start;
        std::cout << "Deque: " << elapsed.count() << "s" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}