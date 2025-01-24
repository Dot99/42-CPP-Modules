/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:46:45 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/24 12:20:07 by gude-jes         ###   ########.fr       */
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
	std::cout << "BitcoinExchange assignation operator called" << std::endl;
	if (this != &other)
	{
		_bitcoinValues = other._bitcoinValues;
	}
	return (*this);
}

double stringToDouble(const std::string& str) {
    std::stringstream ss(str);
    double result;
    ss >> result;
    return result;
}

void BitcoinExchange::loadExchangeRates(const std::string &file, const std::string &inputFile)
{
	std::ifstream exchangeRates(file.c_str());
	if(!exchangeRates.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string line;
	while(std::getline(exchangeRates, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string strRate;
		if(std::getline(iss, date, ',') && std::getline(iss, strRate))
		{
			try
			{
				double rate = stringToDouble(strRate);
				_bitcoinValues[date] = rate;
			}
			catch(const std::exception& e)
			{
				std::runtime_error("Invalid data in file. Line: " + line);
			}
			
		}
	}
	fileHandling(inputFile);
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
	// if(date.size() != 10 || date[4] != '-' || date[7] != '-')
	// 	return (false);
	// int year, month, day;
	// try
	// {
	// 	year = stringToInt(date.substr(0, 4));
	// 	month = stringToInt(date.substr(5, 2));
	// 	day = stringToInt(date.substr(8, 2));
	// }
	// catch(const std::exception &e)
	// {
	// 	throw InvalidDateException();
	// }
	// if(month == 2)
	// {
	// 	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	// 	if(isLeapYear && day > 29)
	// 	{
	// 		return (false);
	// 	}
	// 	else if (!isLeapYear && day > 28)
	// 	{
	// 		return (false);
	// 	}
	// }
	// if(month < 1 || month > 12 || day < 1 || day > 31)
	// 	return (false);
	// if(month == 4 || month == 6 || month == 9 || month == 11)
	// {
	// 	if(day > 30)
	// 		return (false);
	// }
	// return true;
	struct tm tm;
	if(strptime(date.c_str(), "%Y-%m-%d", &tm) == NULL)
	{
		return false;
	}
	return true;
}

bool BitcoinExchange::isValidValue(double &value)
{
	return(value >= 0.0 && value <= 1000.0);
}

void BitcoinExchange::fileHandling(const std::string &inputFile)
{
	std::ifstream file(inputFile.c_str());
	if(!file.is_open())
	{
		throw std::runtime_error("Error: could not open file.");
	}
	std::string line;
	while(std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string strValue;
		if(std::getline(iss, date, '|') && std::getline(iss, strValue))
		{
			date.erase(date.find_last_not_of(" \n\r\t") + 1); //Trim whitespaces
			strValue.erase(0, strValue.find_first_not_of(" \n\r\t")); //Trim whitespaces
			try
			{
				double value = stringToDouble(strValue);
				if(!isValidDate(date))
				{
					std::cerr << "Invalid date: " << date << std::endl;
					continue;
				}
				if(!isValidValue(value))
				{
					std::cerr << "Invalid value: " << value << std::endl;
					continue;
				}
				std::map<std::string, double>::iterator it;
				it = _bitcoinValues.find(date);
				double result;
				if(it != _bitcoinValues.end())
				{
					result = value * it->second;
					std::cout << date << "=>>" << value << "=" << result << std::endl;
				}
				else
				{
					it = _bitcoinValues.lower_bound(date);
					if(it != _bitcoinValues.begin())
					{
						--it;
						result = value * it->second;
						std::cout << date << "=>>" << value << " = " << result << std::endl;
					}
					else
					{
						std::cerr << "Error: No exchange rate found for date " << date << std::endl;
					}
				}
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: Invalid input line" << std::endl;
			}
		}
		else
		{
			std::cerr << "Error: Invalid input line" << std::endl;
		}
	}
}