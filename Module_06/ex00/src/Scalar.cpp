/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:52:23 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/06 16:41:08 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar(const std::string input) : _input(input)
{
	std::cout << "Constructor called" << std::endl;
	_type = checkInput();
	if (_type == 0 || _type == -1)
	{
		if(_type == -1)
			throw NonDisplayable();
		else
			throw Impossible();
	}
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

const char *Scalar::NonDisplayable::what() const throw()
{
	return ("Non displayable");
}

const char *Scalar::Impossible::what() const throw()
{
	return ("Impossible");
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
		if(this->getInput().find_first_of(".") == this->getInput().find_last_of(".") || //Catch 0..0
		std::isdigit(this->getInput()[this->getInput().find_first_of(".") + 1] == false) || // Catch 0.
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
	if (_type == 1)
		fromChar();
	else if (_type == 2)
		fromInt();
	else if (_type == 3)
		fromFloat();
	else if (_type == 4)
		fromDouble();
}

void Scalar::fromChar(void)
{
	_char = _input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	printOutput();
}

void Scalar::fromInt(void)
{
	_int = std::atoi(_input.c_str());
	if (_int < 32 || _int > 126)
		throw NonDisplayable();
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	printOutput();
}

void Scalar::fromFloat(void)
{
	_float = std::atof(_input.c_str());
	_int = static_cast<int>(_float);
	if (_int < 32 || _int > 126)
		throw NonDisplayable();
	if (_float < std::numeric_limits<float>::min() || _float > std::numeric_limits<float>::max())
		throw Impossible();
	_char = static_cast<char>(_int);
	_double = static_cast<double>(_float);
	printOutput();
}

void Scalar::fromDouble(void)
{
	_double = std::atof(_input.c_str());
	_int = static_cast<int>(_double);
	if (_int < 32 || _int > 126)
		throw NonDisplayable();
	if (_double < std::numeric_limits<double>::min() || _double > std::numeric_limits<double>::max())
		throw Impossible();
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_double);
	printOutput();
}

void Scalar::printOutput(void)const
{
	try
	{
		std::cout << "char: ";
		if (_type == 1)
		{
			if (isprint(_char))
				std::cout << "'" << _char << "'" << std::endl;
			else
				throw NonDisplayable();
		}
		else if (_type == 2)
		{
			if (isprint(_char))
				std::cout << "'" << _char << "'" << std::endl;
			else
				throw NonDisplayable();
		}
		else if (_type == 3)
		{
			if (isprint(_char))
				std::cout << "'" << _char << "'" << std::endl;
			else
				throw NonDisplayable();
		}
		else if (_type == 4)
		{
			if (isprint(_char))
				std::cout << "'" << _char << "'" << std::endl;
			else
				throw NonDisplayable();
		}
		std::cout << "int: " << _int << std::endl;
		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
	catch (NonDisplayable &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Impossible &e)
	{
		std::cout << e.what() << std::endl;
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