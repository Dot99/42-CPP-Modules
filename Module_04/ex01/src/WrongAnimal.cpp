/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:27:45 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/20 11:52:24 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
	std::cout << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}


WrongAnimal & WrongAnimal::operator=(WrongAnimal const & obj)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}