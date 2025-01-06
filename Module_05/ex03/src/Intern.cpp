/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:05:16 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 10:31:56 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &src) {
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &src)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) {
    AForm *(*form[3])(std::string const &target) = {
        &ShrubberyCreationForm::createShrubberyCreationForm,
        &RobotomyRequestForm::createRobotomyRequestForm,
        &PresidentialPardonForm::createPresidentialPardonForm
    };
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++) {
        if (formNames[i] == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return (form[i](target));
        }
    }
    std::cout << "Intern cannot create " << formName << std::endl;
    throw AForm::FormCreationException();
}