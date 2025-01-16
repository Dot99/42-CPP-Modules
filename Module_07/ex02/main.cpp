/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:56:34 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/16 14:25:39 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_NUM 500

int main(void)
{
	Array<int> intArray(MAX_NUM);
	int *copy = new int[MAX_NUM];
	srand(time(NULL));
	for (int i = 0; i < MAX_NUM; i++)
	{
		const int value = rand() % MAX_NUM;
		intArray[i] = value;
		copy[i] = value;
	}
	{
		Array<int> tmp;
		try
		{
			for (int i = 0; i < MAX_NUM; i++)
			{
				std::cout << "tmp[" << i << "] = " << tmp[i] << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << "Caught an exception" << std::endl;
		}
		tmp = intArray;
		Array<int> test(tmp);
		try
		{
			for (int i = 0; i < MAX_NUM; i++)
			{
				if(tmp[i] != test[i])
				{
					std::cerr << "Error: tmp[" << i << "] = " << tmp[i] << " != test[" << i << "] = " << test[i] << std::endl;
					return 1;
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			std::cerr << "Caught an exception" << std::endl;
		}
		std::cout << "test[1]: " << test[1] << std::endl;
		std::cout << "tmp[1]: " << tmp[1] << std::endl;
		test[1] = 123456789;
		std::cout << "test[1]: " << test[1] << std::endl;
		std::cout << "tmp[1]: " << tmp[1] << std::endl;
	}
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (intArray[i] != copy[i])
		{
			std::cerr << "Error: intArray[" << i << "] = " << intArray[i] << " != copy[" << i << "] = " << copy[i] << std::endl;
			return 1;
		}
	}
	try
	{
		intArray[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		intArray[MAX_NUM] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for (int i = 0; i < MAX_NUM; i++)
	{
		intArray[i] = rand();
	}
	delete [] copy;
	return (0);
}