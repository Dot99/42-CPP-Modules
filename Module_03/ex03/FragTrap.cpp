/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:05:47 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/18 12:08:30 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap Constructor called!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &fragTrap) : ClapTrap(fragTrap){
	std::cout << "FragTrap Copy constructor called!" << std::endl;
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(FragTrap const &other){
	std::cout << "FragTrap Assignation operator called!" << std::endl;
	if(this != &other){
		this->_name = other._name;
		this->_hitpoints = other._hitpoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " is dead!" << std::endl;
	std::cout << "Destructor called!" << std::endl;
}

FragTrap::FragTrap(std::string name){
	this->_name = name;
	this->_hitpoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " is alive!" << std::endl;
	std::cout << "FragTrap Name constructor called!" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->_name << " says: High five, guys!" << std::endl;
}