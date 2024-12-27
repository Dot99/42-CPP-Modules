/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:23:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 09:45:04 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"	
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "----------AAnimal----------" << std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;

		i->makeSound();
		j->makeSound();

		delete j;
		delete i;

	}
	return 0;
}