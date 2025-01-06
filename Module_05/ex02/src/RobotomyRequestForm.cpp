/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:21:56 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 08:53:44 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & obj) : AForm(obj)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = obj;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & obj)
{
	std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
	if (this != &obj)
	{
		_target = obj._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));
	int randNum = rand() % 2;
	AForm::execute(executor);
	std::cout << "*drilling noises* " << std::endl;
	if (randNum)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << _target << " robotomization failed." << std::endl;
}

std::ostream &operator<<(std::ostream & o, RobotomyRequestForm const & obj)
{
	// o << obj.getName() << " is " << (obj.getSigned() ? "" : "not ") << "signed, it requires grade " << obj.getGradeToSign() << " to sign, and grade " << obj.getGradeToExecute() << " to execute." << std::endl;
	// return (o);
	o << "Form: " << obj.getName() << std::endl;
	o << "Signed: " << obj.getSigned() << std::endl;
	o << "Sign Grade: " << obj.getGradeToSign() << std::endl;
	o << "Execution Grade: " << obj.getGradeToExecute() << std::endl;
	return (o);
}