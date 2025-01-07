/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:52:23 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/07 11:35:05 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(const std::string input) : _input(input)
{
	std::cout << "Constructor called" << std::endl;
	_type = checkInput();
	convertInput();
}

Scalar::Scalar(const Scalar &src) : _input(src.getInput())
{
	std::cout << "Copy constructor called" << std::endl;
	_type = src.getType();
	_char = src.getChar();
	_int = src.getInt();
	_float = src.getFloat();
	_double = src.getDouble();
}

Scalar::~Scalar()
{
	std::cout << "Destructor called" << std::endl;
}

Scalar &Scalar::operator=(const Scalar &src)
{
	if (this == &src)
		return (*this);
	_type = src.getType();
	_char = src.getChar();
	_int = src.getInt();
	_float = src.getFloat();
	_double = src.getDouble();
	return (*this);
}

int Scalar::checkInput(void)
{
	if(this->getInput() == "nan" || this->getInput() == "-inff" || this->getInput() == "+inff"
	|| this->getInput() == "-inf" || this->getInput() == "+inf")
	{
		return (-1); //NAN or INF
	}
	else if (_input.length() == 1 && this->getInput()[0] != '+' && this->getInput()[0] != '-' && this->getInput()[0] != '.' && this->getInput()[0] != 'f')
	{
		return (1); // CHAR
	}
	else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
	{
		return (0); // ERROR
	}
	else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
	{
		return (2); // INT
	}
	else if(this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if(this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || //Catch 0..0
		std::isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false || // Catch 0.n
		this->getInput().find_first_of(".") == 0) //Catch .0
		{
			return (0); //Error
		}
		else
		{
			return (3); // DOUBLE
		}
	}
	else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") || // CATCH 0.0ff
			this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // CATCH 0..0f
			this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 || //CATCH 0.f
			this->getInput().find_first_of(".") == 0 || // CATCH .0f
			this->getInput()[this->getInput().find_first_of("f") + 1] != '\0') // CATCH 0.0f0
		{
			return (0); // ERROR
		}
		else
		{
			return (4); // FLOAT
		}
	}
	else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
		(this->getInput().length() == 1 && std::isalpha(this->getInput()[0])))
	{
		return(1); //CHAR
	}
	else
	{
		return (0); //ERROR
	}
}

void Scalar::convertInput(void)
{
	if(_type == 0)
		return;
	else if (_type == 1)
		fromChar();
	else if (_type == 2)
		fromInt();
	else if (_type == 3)
		fromFloat();
	else if (_type == 4 || _type == -1)
		fromDouble();
}

void Scalar::fromChar(void)
{
	if(std::isdigit(_input[0]))
		_char = static_cast<char>(std::atoi(_input.c_str()));
	else
		_char = _input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	printOutput();
}

void Scalar::fromInt(void)
{
	_int = std::atoi(_input.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	printOutput();
}

void Scalar::fromFloat(void)
{
	_float = std::atof(_input.c_str());
	_int = static_cast<int>(_float);
	_char = static_cast<char>(_int);
	_double = static_cast<double>(_float);
	printOutput();
}

void Scalar::fromDouble(void)
{
	_double = std::atof(_input.c_str());
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_double);
	printOutput();
}

void Scalar::printOutput(void)const
{
	//CHAR
	std::cout << "char: ";
	if(this->getType() != -1 && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
	{
		if(std::isprint(this->getChar()))
			std::cout << "'" << this->getChar() << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	//INT
	std::cout << "int: ";
	if(this->getType() != -1 && this->getDouble() >= std::numeric_limits<int>::min() && this->getDouble() <= std::numeric_limits<int>::max())
		std::cout << this->getInt() << std::endl;
	else
		std::cout << "impossible" << std::endl;
	//FLOAT
	std::cout << "float: ";
	if(this->getType() != -1)
		if(this->getDouble() - this->getInt() == 0)
			std::cout << this->getFloat() << ".0f" << std::endl;
		else
			std::cout << this->getFloat() << "f" << std::endl;
	else
	{
		if(this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "nanf" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	//DOUBLE
	std::cout << "double: ";
	if(this->getType() != -1)
	{
		std::cout << this->getDouble();
		if(this->getDouble() - this->getInt() == 0 || this->getDouble() < std::numeric_limits<double>::min() || this->getDouble() > std::numeric_limits<double>::max())
			std::cout << ".0" << std::endl;
		else
			std::cout << std::endl;
	}
	else
	{
		if(this->getInput() == "nan" || this->getInput() == "nanf")
			std::cout << "nan" << std::endl;
		else if (this->getInput()[0] == '+')
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
}

std::string Scalar::getInput(void)const
{
	return (_input);
}

int Scalar::getType(void)const
{
	return (_type);
}

char Scalar::getChar(void)const
{
	return (_char);
}

int Scalar::getInt(void)const
{
	return (_int);
}

float Scalar::getFloat(void)const
{
	return (_float);
}

double Scalar::getDouble(void)const
{
	return (_double);
}