/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:46:47 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/24 11:48:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <ctime>
#include <exception> //Not necessary but good pratice

class BitcoinExchange
{
	private:
		std::map<std::string, double> _bitcoinValues;
		bool isValidDate(const std::string &date);
		bool isValidValue(double &value);
		void fileHandling(const std::string &inputFile);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void loadExchangeRates(const std::string &file, const std::string &inputFile);
		class InvalidDateException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Invalid date");
			}
		};
		class InvalidValueException : public std::exception
		{
			virtual const char *what() const throw()
			{
				return ("Invalid value");
			}
		};
};