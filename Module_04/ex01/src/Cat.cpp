/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:08:45 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/23 11:40:50 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	_brain = new Brain();
	std::cout << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
	std::cout << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
	std::cout << "Cat parameterized constructor called" << std::endl;
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

Brain *Cat::getBrain() const{
    return _brain;
}