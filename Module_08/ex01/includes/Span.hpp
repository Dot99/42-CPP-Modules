/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:59 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/21 09:47:10 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_v;
		Span();
	public:
		Span(unsigned int N);
		Span(Span const &obj);
		~Span();
		Span &operator=(Span const &obj);

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		void	addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	addNumbers(int *begin, int *end);
		class FullSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class NoSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
		class InvalidSpanException : public std::exception
		{
			virtual const char* what() const throw();
		};
};