/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:43:29 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 08:47:11 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource default constructor called" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &src)
{
	std::cout << "IMateriaSource copy constructor called" << std::endl;
	*this = src;
}

IMateriaSource &IMateriaSource::operator=(IMateriaSource const & other)
{
	(void)other;
	std::cout << "IMateriaSource assignation operator called" << std::endl;
	return (*this);
}

