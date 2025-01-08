/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:34 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/08 09:14:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string s1;
	std::string s2;
	int n;

	Data() : s1(""), s2(""), n(0) {}
	Data(std::string s1, std::string s2, int n) : s1(s1), s2(s2), n(n) {}
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

		uintptr_t serialize(Data *data);
		Data *deserialize(uintptr_t raw);
};