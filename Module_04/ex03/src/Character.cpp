/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:35:44 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 13:44:13 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default"), _inventory()
{
	std::cout << "Character Default constructor called" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "Character Destructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name), _inventory()
{
	std::cout << "Character constructor called" << std::endl;
}

Character &Character::operator=(Character const &copy)
{
	this->_name = copy._name;
	return *this;
}

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::setName(std::string const &name)
{
	this->_name = name;
}

bool Character::InInventory(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == m)
			return true;
	}
	return false;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_inventory[i] == NULL)
		{
			if(this->InInventory(m))
			{
				this->_inventory[i] = m->clone();
			}
			else
				this->_inventory[i] = m;
			std::cout << "Equiped " << m->getType() << " at index " << i << std::endl;
			return;
		}
	}
	if(m)
		std::cout << "Inventory is full, cannot equip " << m->getType() << std::endl;
	else
		std::cout << "Inventory is full, cannot equip invalid Materia" << std::endl;
	if(!this->InInventory(m))
		delete m;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Invalid index or empty inventory" << std::endl;
}