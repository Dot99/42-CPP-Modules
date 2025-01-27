/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:46:50 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 12:00:46 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Usage: ./PmergeMe [file]" << std::endl;
		return 1;
	}
	else
	{
		PmergeMe pmergeMe;
		pmergeMe.run(argc, argv);
	}
	return 0;
}