/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:54:28 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 08:42:29 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is:" << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "-----------" << std::endl;
		Span sp = Span(5);
		for(size_t i = 0; i < 5; i++)
		{
			try
			{
				sp.addNumber(i);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is:" << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(10000);
		sp.addRandomNumbers(10000);
		std::cout << "Shortest Span is: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is:" << sp.longestSpan() << std::endl;
	}
	return 0;
}