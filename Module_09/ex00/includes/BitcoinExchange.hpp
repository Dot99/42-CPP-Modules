/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:46:47 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/23 17:00:27 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _bitcoinValues;
		void loadExchangeRates(const std::string &file);
		bool isValidDate(const std::string &date);
		bool isValidValue(const std::string &value);
		int fileHandling(std::string file);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);
};