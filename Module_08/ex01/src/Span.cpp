/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:29:43 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/21 09:55:18 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0), _v(std::vector<int>())
{
}

Span::Span(unsigned int N) : _N(N), _v(std::vector<int>())
{
}

Span::Span(Span const &obj)
{
	*this = obj;
}

Span::~Span()
{
}

Span &Span::operator=(Span const &obj)
{
	if (this != &obj)
	{
		_N = obj._N;
		_v = obj._v;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_v.size() >= _N)
		throw FullSpanException();
	_v.push_back(n);
}

int Span::shortestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < min)
			min = tmp[i + 1] - tmp[i];
	}
	return (min);
}

int Span::longestSpan()
{
	if (_v.size() <= 1)
		throw NoSpanException();
	std::vector<int> tmp = _v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (_v.size() + std::distance(begin, end) > _N)
		throw FullSpanException();
	_v.insert(_v.end(), begin, end);
}

void Span::addNumbers(int *begin, int *end)
{
	for(int *it = begin; it != end; ++it)
	{
		if (_v.size() >= _N)
			throw FullSpanException();
		addNumber(*it);
	}
}

const char *Span::FullSpanException::what() const throw()
{
	return ("Span is full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}

const char *Span::InvalidSpanException::what() const throw()
{
	return ("Invalid span");
}
