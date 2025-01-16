/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:29:42 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/16 13:55:17 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void ft_toUpper(char &c)
{
    c = std::toupper(static_cast<unsigned char>(c));
}

void ft_toLower(char &c)
{
    c = std::tolower(static_cast<unsigned char>(c));
}

int main(void)
{
	char arr[] = {'a', 'b', 'c'};

	::iter(arr, 3, ft_toUpper);
    std::cout << "Upper" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	::iter(arr, 3, ft_toLower);
    std::cout << "Lower" << std::endl;
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
	return (0);
}