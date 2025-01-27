/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:46:22 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 12:22:27 by gude-jes         ###   ########.fr       */
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


PmergeMe::_sortContainers()
{

}

PmergeMe::_printOutput()
{
	std::cout << "Before: "
	for (std::deque<std::string>::iterator it = _deque.begin(); it != _deque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	_sortContainers();
	std::cout << "After: ";

}

PmergeMe::run(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		int num;
		std::istringstream iss(argv[i]);
		if(!(iss >> num))
		{
			std::cerr << "Error: Invalid argument" << std::endl;
			return;
		}
		_deque.push_back(argv[i]);
		_vector.push_back(argv[i]);
	}
	_printOutput();
}