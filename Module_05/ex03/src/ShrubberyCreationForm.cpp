/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:22:17 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 09:24:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
		std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src) {
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &src)
		_target = src._target;
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file.is_open())
		throw AForm::FileNotOpenedException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\/\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\/\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/O/\\" << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << "      ||      " << std::endl;
	file << std::endl;
	file.close();
}

AForm *ShrubberyCreationForm::createShrubberyCreationForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm const &shrubberyCreationForm) {
	out << "Form: " << shrubberyCreationForm.getName() << std::endl;
	out << "Signed: " << shrubberyCreationForm.getSigned() << std::endl;
	out << "Sign Grade: " << shrubberyCreationForm.getGradeToSign() << std::endl;
	out << "Execution Grade: " << shrubberyCreationForm.getGradeToExecute() << std::endl;
	return (out);
}