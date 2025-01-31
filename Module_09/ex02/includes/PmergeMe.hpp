/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:46:24 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/29 09:31:00 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

class PmergeMe
{
	private:
		std::deque<int> _deque;
		std::vector<int> _vector;
		void printOutput();
		void mergeInsertionSortVector(std::vector<int> &arr);
		void mergeInsertionSortDeque(std::deque<int> &arr);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
		void run(int argc, char **argv);
};
