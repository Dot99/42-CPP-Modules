/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:51:36 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/27 11:27:26 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
	private:
		std::stack<int> _stack;
		std::string _rpn;
		void _parseRPN();
		void _printOutput();
	public:
		RPN();
		RPN(RPN const & other);
		RPN & operator=(RPN const & other);
		~RPN();
		void loadRPN(std::string rpn);
};