/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:40:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/18 12:12:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){
	std::cout << "Diamond Trap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
	this->_name = name;
	std::cout << "Diamond Trap Name Constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Diamond Trap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->_name << "_clap_name" << std::endl;
}