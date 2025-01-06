/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:44:50 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 11:45:56 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		std::cout << "Test 1" << std::endl;
		std::cout << "Failed Tests" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 150);
		std::cout << *bureaucrat << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		std::cout << *shrubbery << std::endl;
		bureaucrat->signForm(*shrubbery);
		bureaucrat->executeForm(*shrubbery);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Home");
		std::cout << *robotomy << std::endl;
		bureaucrat->signForm(*robotomy);
		bureaucrat->executeForm(*robotomy);
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Home");
		std::cout << *presidential << std::endl;
		bureaucrat->signForm(*presidential);
		bureaucrat->executeForm(*presidential);
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl;
	}
	{
		std::cout << "------Test 2------" << std::endl;
		std::cout << "------Sucessuful Test------" << std::endl;
		Bureaucrat *bureaucrat = new Bureaucrat("Abilio", 1);
		std::cout << *bureaucrat << std::endl;
		ShrubberyCreationForm *shrubbery = new ShrubberyCreationForm("Home");
		std::cout << *shrubbery << std::endl;
		bureaucrat->signForm(*shrubbery);
		bureaucrat->executeForm(*shrubbery);
		RobotomyRequestForm *robotomy = new RobotomyRequestForm("Robocop");
		std::cout << *robotomy << std::endl;
		bureaucrat->signForm(*robotomy);
		bureaucrat->executeForm(*robotomy); //50% chance of success
		PresidentialPardonForm *presidential = new PresidentialPardonForm("Emilio");
		std::cout << *presidential << std::endl;
		bureaucrat->signForm(*presidential);
		bureaucrat->executeForm(*presidential);
		delete bureaucrat;
		delete shrubbery;
		delete robotomy;
		delete presidential;
		std::cout << std::endl;
	}
}