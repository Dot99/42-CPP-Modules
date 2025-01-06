/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:03:00 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 16:35:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return 1;
	}
	Scalar scalar(argv[1]);
	return 0;
}