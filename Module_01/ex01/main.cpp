/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:56:28 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/11 10:21:03 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	std::string zombieName;
	int zombieNumber = 0;
	while(!std::cin.eof())
	{
		std::cout << "Enter the number of zombies(>0 && <100):";
		std::cin >> zombieNumber;
		if(std::cin.fail() || zombieNumber <= 0 || zombieNumber > 100){
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please try again." << std::endl;
		}
		else
			break;
	}
	if(std::cin.eof())
		return 0;
	std::cout << "Enter the name of the zombies:" << std::endl;
	std::cin >> zombieName;
	Zombie *horde = zombieHorde(zombieNumber, zombieName);
	if(!horde)
	{
		std::cout << "Memory allocation failed." << std::endl;
		return 1;
	}
	for(int i = 0; i < zombieNumber; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}