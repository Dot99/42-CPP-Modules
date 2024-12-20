/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:08:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/20 10:13:40 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	std::cout << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	std::cout << std::endl;
}

Dog::Dog(const Dog &src) : Animal::Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	std::cout << std::endl;
	*this = src;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignation operator called" << std::endl;
	std::cout << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}