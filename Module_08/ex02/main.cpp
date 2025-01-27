/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:01:53 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 08:44:06 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();

		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "Size: " << mstack.size() << std::endl;
		int i = 0;
		while (it != ite)
		{
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
			++it;
			i++;
		}

		std::stack<int> s(mstack);
	}
	{
		std::cout << "---------------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		int i = 0;
		while (it != ite)
		{
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
			++it;
			i++;
		}
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		i = 0;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
			++it;
			i++;
		}
	}
	return 0;
}