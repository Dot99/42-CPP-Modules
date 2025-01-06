/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:21:40 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 09:22:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &obj) : AForm(obj), _target(obj._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	std::cout << "PresidentialPardonForm assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	AForm::operator=(obj);
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

AForm *PresidentialPardonForm::createPresidentialPardonForm(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &obj)
{
	o << "Form: " << obj.getName() << std::endl;
	o << "Signed: " << obj.getSigned() << std::endl;
	o << "Sign Grade: " << obj.getGradeToSign() << std::endl;
	o << "Execution Grade: " << obj.getGradeToExecute() << std::endl;
	o << "Target: " << obj.getTarget() << std::endl;
	return (o);
}