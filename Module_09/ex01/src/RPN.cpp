/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:34 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 11:56:16 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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
		_rpn = other._rpn;
		_stack = other._stack;
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
		if(std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])) || (token[0] == '+' && std::isdigit(token[1])))
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
}

void RPN::_printOutput()
{
	std::istringstream iss(_rpn);
	std::string token;
	while(iss >> token)
	{
		if(std::isdigit(token[0]) || (token[0] == '-' && std::isdigit(token[1])) || (token[0] == '+' && std::isdigit(token[1])))
		{
			int num;
			std::stringstream ss(token);
			ss >> num;
			_stack.push(num);
		}
		else if (token == "+" || token == "-" || token =="*" || token == "/")
		{
			if(_stack.size() < 2)
			{
				std::cout << "Error: not enough operands" << std::endl;
				return;
			}
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			if(token == "+")
				_stack.push(a + b);
			else if(token == "-")
				_stack.push(a - b);
			else if(token == "*")
				_stack.push(a * b);
			else if(token == "/")
			{
				if(b == 0)
				{
					std::cout << "Error: division by zero" << std::endl;
					return;
				}
				_stack.push(a / b);
			}
		}
		else
		{
			std::cout << "Error: invalid token" << std::endl;
			return;
		}	
	}
	if(_stack.size() == 1)
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Result: " << _stack.top() << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		std::cout << "Error: invalid RPN expression" << std::endl;
	}
}

void RPN::loadRPN(std::string rpn)
{
	_rpn = rpn;
	_parseRPN();
	_printOutput();
}