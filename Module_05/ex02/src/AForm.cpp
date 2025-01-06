/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:38:52 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 08:42:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "AForm Parametric constructor called" << std::endl;
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const & obj) : _name(obj._name), _signed(obj._signed), _signGrade(obj._signGrade), _execGrade(obj._execGrade)
{
	std::cout << "Copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const & obj)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_signGrade);
}

int AForm::getGradeToExecute() const
{
	return (_execGrade);
}

void AForm::beSigned(Bureaucrat const & obj)
{
	if (obj.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

const char* AForm::FileNotOpenedException::what() const throw()
{
	return ("File not opened");
}

std::ostream &operator<<(std::ostream &o, AForm const & obj)
{
	o << "Form: " << obj.getName() << std::endl;
	o << "Signed: " << obj.getSigned() << std::endl;
	o << "Grade to sign: " << obj.getGradeToSign() << std::endl;
	o << "Grade to execute: " << obj.getGradeToExecute() << std::endl;
	return (o);
}