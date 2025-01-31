/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:46:22 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/31 10:06:17 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << "PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	std::cout << "PmergeMe assignation operator called" << std::endl;
	if (this != &other)
	{
		_deque = other._deque;
		_vector = other._vector;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

void PmergeMe::printOutput()
{
	std::cout << "Before: ";
	for(size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i];
		if (i < _vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	clock_t start_deque = clock();
	mergeInsertionSortDeque(_deque);
	clock_t end_deque = clock();
	clock_t start_vector = clock();
	mergeInsertionSortVector(_vector);
	clock_t end_vector = clock();
	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); i++)
	{
		std::cout << _vector[i];
		if (i < _vector.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process range of " << _deque.size() << " elements with std::deque : " << (double)(end_deque - start_deque) * 100000 / CLOCKS_PER_SEC << "us" << std::endl;
	std::cout << "Time to process range of " << _vector.size() << " elements with std::vector : " << (double)(end_vector - start_vector) * 1000000 / CLOCKS_PER_SEC << "us" << std::endl;

}

void PmergeMe::mergeInsertionSortDeque(std::deque<int> &arr)
{
	if (arr.size() <= 1) 
		return;
    size_t mid = arr.size() / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());
    
    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);
    
    std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

void PmergeMe::mergeInsertionSortVector(std::vector<int> &arr)
{
	if(arr.size() <= 1)
		return;
	size_t mid = arr.size() / 2;
	std::vector<int> left(arr.begin(), arr.begin() + mid);
	std::vector<int> right(arr.begin() + mid, arr.end());
	mergeInsertionSortVector(left);
	mergeInsertionSortVector(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), arr.begin());
}

std::vector<std::string> split(const std::string& s, const std::string& delimiter) {
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;
	std::string str = s; // Create a modifiable copy of s
	while ((pos = str.find(delimiter)) != std::string::npos) {
		token = str.substr(0, pos);
		tokens.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	tokens.push_back(str);

	return tokens;
}

void PmergeMe::run(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        std::string token;
        while (iss >> token)
        {
			bool isValid = true;
			for (size_t j = 0; j < token.size(); ++j)
            {
				if (!std::isdigit(token[j]))
                {
                    isValid = false;
                    break;
                }
            }
            if (!isValid)
            {
                std::cerr << "Error: Invalid argument" << std::endl;
                return;
            }
            try
            {
				int num;
				std::stringstream ss(token);
				ss >> num;
				if (ss.fail())
				{
					std::cerr << "Error: Invalid argument" << std::endl;
					return;
				}
                if (num < 0)
                {
                    std::cerr << "Error: Invalid argument" << std::endl;
                    return;
                }
                _deque.push_back(num);
                _vector.push_back(num);
            }
            catch (const std::invalid_argument &)
            {
                std::cerr << "Error: Invalid argument" << std::endl;
                return;
            }
        }
    }
	printOutput();
}