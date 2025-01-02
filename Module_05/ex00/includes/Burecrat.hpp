/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Burecrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:24:19 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/02 17:26:53 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Burecrat
{
	private:
		std::string const _name;
		int _grade;
		void setGrade(int grade);
	public:
		Burecrat(std::string const name, int grade);
		Burecrat(Burecrat const &other);
		~Burecrat();
		Burecrat &operator=(Burecrat const &other);
		std::string const &getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
