/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:46:45 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/23 17:02:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = other;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;
	std::cout << "BitcoinExchange assignation operator called" << std::endl;
	return (*this);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	if(date.length() != 10)
		return false;
	return true;
}

// int BitcoinExchange::fileHandling(std::string file)
// {
// 	std::ifstream infile(file.c_str());
// 	if(!infile)
// 	{
// 		std::cout << "File not found" << std::endl;
// 		return(1);
// 	}
// 	return(0);
// }