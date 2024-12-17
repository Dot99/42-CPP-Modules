/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:10:17 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/17 10:25:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " is alive!" << std::endl;
	std::cout << "Constructor called!" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	std::cout << "Destructor called!" << std::endl;
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