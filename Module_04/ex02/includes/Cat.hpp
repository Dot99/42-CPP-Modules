/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 09:05:31 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 09:45:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		virtual ~Cat();
		Cat(const std::string &type);
		Cat(const Cat &src);
		Cat &operator=(const Cat &src);
		void makeSound() const;
		Brain *getBrain() const;
	private:
		Brain *_brain;
};