/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:03:50 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 09:58:10 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ICharacter;
class AMateria
{
	protected:
		std::string _type;
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
	public:
		virtual ~AMateria();
		AMateria &operator=(AMateria const &other);
		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
};