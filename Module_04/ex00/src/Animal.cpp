/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:08:28 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/20 10:13:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	std::cout << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
	std::cout << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	std::cout << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	std::cout << std::endl;
}

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}