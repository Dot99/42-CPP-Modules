/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 08:47:59 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/21 09:25:15 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Element not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &vec, int i)
{
	typename T::iterator it = std::find(vec.begin(), vec.end(), i);
	if (it == vec.end())
		throw NotFoundException();
	return it;
}