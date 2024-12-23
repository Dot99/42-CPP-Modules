/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:23:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/23 11:33:30 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"	
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	{
		std::cout << "----------First Test-----------" << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout << "----------Second Test-----------" << std::endl;
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		animal->makeSound();

		delete animal;
		delete dog;
		delete cat;
	}
	{
		std::cout << "----------Third Test-----------" << std::endl;
		std::cout << "----------Wrong Animal----------" << std::endl;
		const WrongAnimal* wronganimal = new WrongAnimal();
		const WrongAnimal* wrongcat = new WrongCat();
		std::cout << wrongcat->getType() << " " << std::endl;
		wronganimal->makeSound();
		wrongcat->makeSound();

		delete wronganimal;
		delete wrongcat;
	}
	{
		std::cout << "----------Fourth Test-----------" << std::endl;
		std::cout << "----------Animal Brains----------" << std::endl;
		const int size = 100;
		Animal* animal[size];
		for (int i = 0; i < size; i++)
		{
			if(i < size / 2)
			{
				animal[i] = new Dog();
			}
			else
			{
				animal[i] = new Cat();
			}
		}
		for (int i = 0; i < size; i++)
		{
			animal[i]->makeSound();
		}
		for (int i = 0; i < size; i++)
		{
			delete animal[i];
		}
	}
	return 0;
}