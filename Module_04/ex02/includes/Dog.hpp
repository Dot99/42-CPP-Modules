/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:05:55 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 09:45:51 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog();
		virtual ~Dog();
		Dog(const std::string &type);
		Dog(const Dog &src);
		Dog &operator=(const Dog &src);
		void makeSound() const;
		Brain *getBrain() const;
	private:
		Brain *_brain;
};