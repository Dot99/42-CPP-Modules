/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:30:51 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/20 10:11:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		virtual ~Animal();
		Animal(const std::string &type);
		Animal(const Animal &src);
		Animal &operator=(const Animal &src);
		std::string getType() const;
		virtual void makeSound() const;
};