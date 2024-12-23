/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:58:38 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/23 09:01:31 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
	std::cout << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
	std::cout << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
	std::cout << "WrongCat parameterized constructor called" << std::endl;
	std::cout << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	std::cout << std::endl;
	*this = src;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	std::cout << std::endl;
	if (this != &src)
	{
		WrongAnimal::operator=(src);
		this->_type = src._type;
	}
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Wrong Meow Meow" << std::endl;
}