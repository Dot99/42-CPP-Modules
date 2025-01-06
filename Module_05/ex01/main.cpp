/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:44:50 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/03 11:28:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
		std::cout << *bureaucrat << std::endl;
		Form *form = new Form();
		std::cout << *form << std::endl;
		form->beSigned(*bureaucrat);
		std::cout << *form << std::endl;
		delete form;
		delete bureaucrat;
		std::cout << std::endl;
	}
	{
		std::cout << "Test 2" << std::endl;
		Bureaucrat *b1 = new Bureaucrat("Abilio", 150);
		Bureaucrat *b2 = new Bureaucrat("Emilio", 1);
		std::cout << *b1 << std::endl;
		std::cout << *b2 << std::endl;
		Form *form = new Form("Form", 1, 1);
		std::cout << *form << std::endl;
		try
		{
			form->beSigned(*b1);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			form->beSigned(*b2);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		
		std::cout << *form << std::endl;
		delete form;
		delete b1;
		delete b2;
	}
}