/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:10:17 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/18 12:09:15 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap" << this->_name << " is alive!" << std::endl;
	std::cout << "ClapTrap Constructor called!" << std::endl;
	std::cout << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &clapTrap){
	std::cout << "ClapTrap " << this->_name << " is alive!" << std::endl;
	std::cout << "ClapTrap Copy constructor called!" << std::endl;
	*this = clapTrap;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other){
	std::cout << "ClapTrap Assignation operator called!" << std::endl;
	if(this != &other){
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	std::cout << "ClapTrap Destructor called!" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitpoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap " << this->_name << " is alive!" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if(ClapTrap::_energyPoints == 0){
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	ClapTrap::_energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	ClapTrap::_hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if(ClapTrap::_energyPoints == 0){
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
	ClapTrap::_hitpoints += amount;
	ClapTrap::_energyPoints -= 1;
}