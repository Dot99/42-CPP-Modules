/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:11 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/07 12:19:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Serializer serializer;
	void *raw;
	Data *data;

	srand(time(NULL));
	raw = serializer.serialize();
	data = serializer.deserialize(raw);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;
	delete[] reinterpret_cast<char *>(raw);

	return 0;
}