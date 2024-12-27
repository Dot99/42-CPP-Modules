/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:31:48 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 13:29:50 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::~AMateria()
{
}

AMateria::AMateria(AMateria const & other)
{
	*this = other;
}

AMateria &AMateria::operator=(AMateria const & other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}
