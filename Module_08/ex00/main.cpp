/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:48:03 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/21 09:26:00 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i);
	try
	{
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(vec, 10) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}