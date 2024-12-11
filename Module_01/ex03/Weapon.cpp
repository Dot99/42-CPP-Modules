/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:37:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/11 10:53:37 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
}

Weapon::~Weapon(){
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string const &Weapon::getType(void)
{
	return (this->_type);
}