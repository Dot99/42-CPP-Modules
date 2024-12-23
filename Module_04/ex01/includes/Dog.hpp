/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:05:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/23 11:39:38 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const std::string &type);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		void makeSound() const;
	private:
		Brain *_brain;
};