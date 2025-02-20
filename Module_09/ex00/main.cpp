/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:45:53 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/24 11:07:59 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return(1);
	}
	else
	{
		BitcoinExchange exchange;
		try
		{
			exchange.loadExchangeRates("data.csv", argv[1]);
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
			return (1);
		}
		//exchange.printExchangeRates();
		return (0);
	}
}