/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:43:04 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 12:44:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria* _inventory[4];
	public:
		Character();
		~Character();
		Character(std::string const &name);
		Character(Character const & src);
		Character & operator=(Character const &copy);
		std::string const &getName() const;
		void	setName(std::string const &name);
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		bool InInventory(AMateria *m);
};