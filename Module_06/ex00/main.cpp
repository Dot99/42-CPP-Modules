/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:03:00 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/07 11:37:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char **argv)
{
	if(argc == 2)
		Scalar scalar(argv[1]);
	else
	{
		std::cout << "---0---" << std::endl;
		Scalar scalar("0");
		std::cout << "---42---" << std::endl;
		Scalar scalar2("42");
		std::cout << "---41.5f---" << std::endl;
		Scalar scalar3("41.5f");
		std::cout << "---105.4---" << std::endl;
		Scalar scalar4("105.4");
		std::cout << "---nan---" << std::endl;
		Scalar scalar5("nan");
		std::cout << "---inf---" << std::endl;
		Scalar scalar6("+inf");
		std::cout << std::endl;
	}
	return 0;
}