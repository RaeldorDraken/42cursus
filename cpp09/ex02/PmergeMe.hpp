/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eros-gir <eros-gir@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:35:34 by eros-gir          #+#    #+#             */
/*   Updated: 2024/01/05 18:21:00 by eros-gir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <deque>
# include <stdexcept>
# include <climits>
# include <algorithm>
# include <ctime>
# include <set>

class PmergeMe
{
	public:
		static void		mergeMe(std::string const *argv, size_t size);
	private:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);
		PmergeMe &operator=(PmergeMe const &rhs);

		static void printDeque(std::deque<int> const &deq);
		static void printVector(std::vector<int> const &vec);
		static void mergeAuxVector(std::vector<int> &vec, int start, int mid, int end);
		static void mergeSortVector(std::vector<int> &vec, int start, int end);
		static void mergeAuxDeque(std::deque<int> &deq, int start, int mid, int end);
		static void mergeSortDeque(std::deque<int> &deq, int start, int end);
};

#endif