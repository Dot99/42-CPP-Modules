/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:17:27 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 10:29:23 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception> // Not necessary for the exercise but good practice
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const _name;
		bool _signed;
		int const _signGrade;
		int const _execGrade;
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
	public:
		AForm(AForm const &obj);
		virtual ~AForm();
		AForm &operator=(AForm const & obj);

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const & obj);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FileNotOpenedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormCreationException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, AForm const & obj);