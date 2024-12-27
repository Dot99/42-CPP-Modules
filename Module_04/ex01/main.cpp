/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:23:12 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/27 09:42:43 by gude-jes         ###   ########.fr       */
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
		for (int i = 0; i < size; i++){
			animal[i]->makeSound();
		}
		for (int i = 0; i < size; i++)
		{
			if(Dog *dog = dynamic_cast<Dog*>(animal[i]))
			{
				Brain *dogBrain = dog->getBrain();
				dogBrain->setIdea(0, "I am a dog");
				std::cout << dogBrain->getIdea(0) << std::endl;
			}
			else if(Cat *cat = dynamic_cast<Cat*>(animal[i]))
			{
				Brain *catBrain = cat->getBrain();
				catBrain->setIdea(0, "I am a cat");
				std::cout << catBrain->getIdea(0) << std::endl;
			}
		}
		for (int i = 0; i < size; i++)
		{
			delete animal[i];
		}
	}
	return 0;
}