/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:41:29 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/11 09:49:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name){
	Zombie *zombie = new Zombie[N];
	if(!zombie)
	{
		std::cout << "Error create Zombie" << std::endl;
		return NULL;
	}
	for(int i = 0; i < N; i++)
	{
		zombie[i].setName(name);
	}
	return(zombie);
}