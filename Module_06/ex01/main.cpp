/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:11 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/08 09:17:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void testSerialization(const std::string& s1, const std::string& s2, int n)
{
    Data *data = new Data(s1, s2, n);
	Serializer serializer;
    uintptr_t raw = serializer.serialize(data);
    std::cout << "raw: " << raw << std::endl;

    Data *deserializedData = serializer.deserialize(raw);

    std::cout << "Original Data: " << std::endl;
    std::cout << "s1: " << data->s1 << ", n: " << data->n << ", s2: " << data->s2 << std::endl;

    std::cout << "Deserialized Data: " << std::endl;
    std::cout << "s1: " << deserializedData->s1 << ", n: " << deserializedData->n << ", s2: " << deserializedData->s2 << std::endl;

    delete deserializedData;
    delete data;
    delete[] reinterpret_cast<char *>(raw);
	std::cout << std::endl;
}

int main() {
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Hello", "World", 42);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Foo", "Bar", 123);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Test", "Serialization", 999);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Another", "Test", -1);

    return 0;
}