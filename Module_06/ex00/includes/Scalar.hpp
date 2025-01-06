/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:52:17 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 16:03:51 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <exception> // Not necessary but good pratice

class Scalar
{
	private:
		const std::string _input;
		int _type;
		char _char;
		int _int;
		float _float;
		double _double;
		Scalar();
		int checkInput(void);
		void convertInput(void);
		void fromChar(void);
		void fromInt(void);
		void fromFloat(void);
		void fromDouble(void);

		void printOutput(void)const;
		std::string getInput(void)const;
		int getType(void)const;
		char getChar(void)const;
		int getInt(void)const;
		float getFloat(void)const;
		double getDouble(void)const;
	public:
		Scalar(const std::string input);
		Scalar(const Scalar &src);
		~Scalar();
		Scalar &operator=(const Scalar &src);
		
		class NonDisplayable : public std::exception
		{
		public:
			virtual const char *what() const throw();
		};
		class Impossible : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};