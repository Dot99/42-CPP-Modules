/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:48:24 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/12 09:13:30 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;

	if(argc == 1)
	{
		std::cout << "Usage: ./harl [debug/info/warning/error]" << std::endl;
		return 1;
	}
	else
		harl.complain(argv[1]);
	return 0;
}