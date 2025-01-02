/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burecrat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:23:58 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 17:30:19 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Burecrat.hpp"

Burecrat::Burecrat(std::string const name, int grade) : _name(name)
{
	setGrade(grade);
}

Burecrat::Burecrat(Burecrat const &other) : _name(other._name)
{
	*this = other;
}

Burecrat::~Burecrat()
{
}

Burecrat &Burecrat::operator=(Burecrat const &other)
{
	if (this != &other)
	{
		_grade = other._grade;
	}
	return (*this);
}

std::string const &Burecrat::getName() const
{
	return (_name);
}

int Burecrat::getGrade() const
{
	return (_grade);
}

void Burecrat::incrementGrade()
{
	setGrade(_grade - 1);
}

void Burecrat::decrementGrade()
{
	setGrade(_grade + 1);
}

void Burecrat::setGrade(int grade)
{
	if (grade < 1)
		throw Burecrat::GradeTooHighException();
	else if (grade > 150)
		throw Burecrat::GradeTooLowException();
	_grade = grade;
}

const char *Burecrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char *Burecrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, Burecrat const &burecrat)
{
	out << burecrat.getName() << ", burecrat grade " << burecrat.getGrade();
	return (out);
}