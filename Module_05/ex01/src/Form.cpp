/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:38:52 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/03 11:12:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Form"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
	_signed = false;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	_signed = false;
}

Form::Form(Form const & obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExecute(obj._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	_signed = obj._signed;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form & Form::operator=(Form const & obj)
{
	std::cout << "Form assignation operator called" << std::endl;
	_signed = obj._signed;
	return (*this);
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &signer)
{
	if(signer.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	else if (_signed)
		std::cout << "Form is already signed" << std::endl;
	else
	{
		_signed = true;
		std::cout << "Form signed by " << signer.getName() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &o, Form const &obj)
{
	std::cout << "Form: " << obj.getName() << " is " << (obj.getSigned() ? "" : "not ") << "signed. Grade to sign: " << obj.getGradeToSign() << ". Grade to execute: " << obj.getGradeToExecute() << ".";
	return (o);
}