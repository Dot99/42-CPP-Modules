/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:31 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/08 09:14:26 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer assignation operator called" << std::endl;
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data *data)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(new char[sizeof(Data) + 1]);
	char *raw_char = reinterpret_cast<char *>(raw);

	for (size_t i = 0; i < data->s1.length(); i++)
		raw_char[i] = data->s1[i];
	raw_char[data->s1.length()] = '\0';

	*reinterpret_cast<int *>(raw_char + data->s1.length() + 1) = data->n;

	for (size_t i = 0; i < data->s2.length(); i++)
		raw_char[data->s1.length() + 1 + sizeof(int) + i] = data->s2[i];
	raw_char[data->s1.length() + 1 + sizeof(int) + data->s2.length()] = '\0';

	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data = new Data();
	char *raw_char = reinterpret_cast<char *>(raw);

	data->s1 = raw_char;
	data->n = *reinterpret_cast<int *>(raw_char + data->s1.length() + 1);
	data->s2 = raw_char + data->s1.length() + 1 + sizeof(int);

	return data;
}