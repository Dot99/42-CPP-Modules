/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:08:45 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/20 10:13:30 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	std::cout << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	std::cout << std::endl;
}

Cat::Cat(const Cat &src) : Animal::Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	std::cout << std::endl;
	*this = src;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	std::cout << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}