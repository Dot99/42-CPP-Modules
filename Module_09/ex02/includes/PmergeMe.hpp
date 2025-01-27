/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:46:24 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 12:53:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>

template <typename Iterator>
class PmergeMe
{
	private:
		std::deque <std::string> _deque;
		std::vector <std::string> _vector;
		void merge (Iterator first, Iterator middle, Iterator last);
		void insertionSort(Iterator first, Iterator last);
		void mergeInsertionSort(Iterator first, Iterator last);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		PmergeMe &operator=(PmergeMe const &other);
		~PmergeMe();
		void run(int argc, char **argv);
		void _printOutput();
		void _sortContainers();
};
