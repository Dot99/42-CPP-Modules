/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:24:07 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 10:00:36 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter() {
	std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::ICharacter(ICharacter const &src) {
	*this = src;
	std::cout << "ICharacter copy constructor called" << std::endl;
}

ICharacter const &ICharacter::operator=(ICharacter const &other) {
	(void)other;
	std::cout << "ICharacter assignment operator called" << std::endl;
	return *this;
}