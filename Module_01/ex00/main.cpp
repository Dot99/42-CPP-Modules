/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:21:10 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/10 09:24:07 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
	Zombie *zombie;
	std::string ZombieName;

	std::cout << "Enter the name of the Zombie: ";
	std::getline(std::cin, ZombieName);
	zombie = new Zombie(ZombieName);
	if(!zombie)
	{
		std::cout << "Error create Zombie" << std::endl;
	}
	zombie->announce();
	delete zombie;
	randomChump(ZombieName);
	return 0;
}