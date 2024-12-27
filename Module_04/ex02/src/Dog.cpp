/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:08:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 09:15:13 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	_brain = new Brain();
	std::cout << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
	std::cout << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << "Dog parameterized constructor called" << std::endl;
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
		delete _brain;
		_brain = new Brain(*src._brain);
		this->_type = src._type;
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof" << std::endl;
}

Brain *Dog::getBrain() const{
	return _brain;
}