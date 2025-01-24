/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:49 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/24 12:23:01 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cout << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
		return 1;
	}
	else
	{
		RPN rpn;
		rpn.loadRPN(argv[1]);
	}
	return 0;
}