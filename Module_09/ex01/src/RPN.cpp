/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:34 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/24 12:32:28 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

RPN::RPN()
{
	std::cout << "RPN constructor called" << std::endl;
}

RPN::RPN(RPN const & other)
{
	std::cout << "RPN copy constructor called" << std::endl;
	*this = other;
}

RPN &RPN::operator=(RPN const & other)
{
	std::cout << "RPN assignation operator called" << std::endl;
	if (this != &other)
	{
		// Do the assignment
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "RPN destructor called" << std::endl;
}

void RPN::_parseRPN()
{
	 //Run the string and check if there is more than 10 numbers
	 int numberCount = 0;
	 std::istringstream iss(_rpn);
	 std::string token;
	 while(iss >> token)
	 {
		if(std::isdigit(token[0]))
			numberCount++;
	 }
	 if(numberCount > 10)
	 {
		 std::cout << "Error: too many numbers" << std::endl;
		 return;
	 }
	 if(numberCount == 0)
	 {
		 std::cout << "Error: no numbers" << std::endl;
		 return;
	 }
	 //Can only handle + - * /
	 //Any error print specific error related to the error
	 //If no error proceed to do the operations and print
}

void RPN::loadRPN(std::string rpn)
{
	_rpn = rpn;
	_parseRPN();
	_printOutput();
}