/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:24:07 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 12:30:27 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &src) {
	std::cout << "ICharacter copy constructor called" << std::endl;
	*this = src;
}

ICharacter const &ICharacter::operator=(ICharacter const &rhs) {
	(void)rhs;
	std::cout << "ICharacter assignment operator called" << std::endl;
	return *this;
}