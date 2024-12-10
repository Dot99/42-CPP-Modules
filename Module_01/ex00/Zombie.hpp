/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:10:50 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/10 09:19:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

class Zombie {
	public:
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		static Zombie* newZombie(std::string name);
	private:
		std::string _name;
};

void randomChump(std::string name);