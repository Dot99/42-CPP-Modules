/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:29:42 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/09 12:38:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void ft_toUpper(char &c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

void ft_toLower(char &c)
{
	c =std::tolower(static_cast<unsigned char>(c));
}

int main(void)
{
	std::string stringArray[3] = {"a", "b", "c"};

	std::cout << "String array: " << std::endl;
	::iter(stringArray, 3, ft_toUpper);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << stringArray[i] << std::endl;
	}
	::iter(stringArray, 3, ft_toLower);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << stringArray[i] << std::endl;
	}
	std::cout << std::endl;
	return (0);
}