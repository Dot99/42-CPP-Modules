/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:19:49 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/22 12:01:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <stack>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef std::stack<T> stack;
		typedef typename stack::container_type container;
		typedef typename container::iterator iterator;

		MutantStack() : stack()
		{
			std::cout << "MutantStack constructor" << std::endl;
		}
		MutantStack(MutantStack const &other) : stack(other)
		{
			std::cout << "MutantStack copy constructor" << std::endl;
		}
		~MutantStack()
		{
			std::cout << "MutantStack destructor" << std::endl;
		}
		stack &operator=(MutantStack const &other)
		{
			std::cout << "MutantStack assignation operator" << std::endl;
			if(this != &other)
				*this= other;
			return(*this);
		}
		iterator begin()
		{
			return (stack::c.begin());
		}
		iterator end()
		{
			return (stack::c.end());
		}
};