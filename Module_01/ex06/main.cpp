/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 09:20:35 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/12 09:48:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
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