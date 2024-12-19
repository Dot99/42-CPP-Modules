/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:40:15 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/19 10:37:55 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//Default Constructor
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(){
	std::cout << "Diamond Trap Default Constructor called" << std::endl;
	_hitpoints = FragTrap::_hitpoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

//Parameterized Constructor
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name){
	this->_name = name;
	_hitpoints = FragTrap::_hitpoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = name + "_clap_name";
	std::cout << "Diamond Trap Name Constructor called" << std::endl;
}

//Assignment Operator
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "Diamond Trap Assignment Operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

//Copy Constructor
DiamondTrap::DiamondTrap(DiamondTrap const &diamondTrap) : ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap){
	std::cout << "Diamond Trap Copy Constructor called" << std::endl;
	*this = diamondTrap;
}

//Destructor Constructor
DiamondTrap::~DiamondTrap(){
	std::cout << "Diamond Trap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(){
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->_name << "_clap_name" << std::endl;
}