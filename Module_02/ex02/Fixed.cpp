/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 09:06:31 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/17 09:06:32 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(Fixed const &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called" << std::endl;
	this->_value = value << Fixed::_fractionalBits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << Fixed::_fractionalBits));
}

// Assignment operator
Fixed &Fixed::operator=(Fixed const &fixed) {
	std::cout << "Assignation operator called" << std::endl;
	if (this != &fixed)
		this->_value = fixed.getRawBits();
	return *this;
}

// Value to int
int Fixed::toInt(void) const {
	return this->_value >> Fixed::_fractionalBits;
}

// Value to float
float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << Fixed::_fractionalBits);
}

// Output operator
std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

Fixed Fixed::operator+(Fixed const &fixed) const {
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(Fixed const &fixed) const {
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(Fixed const &fixed) const {
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(Fixed const &fixed) const {
	return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

bool Fixed::operator>(Fixed const &fixed) const {
	return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(Fixed const &fixed) const {
	return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(Fixed const &fixed) const {
	return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(Fixed const &fixed) const {
	return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(Fixed const &fixed) const {
	return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(Fixed const &fixed) const {
	return this->toFloat() != fixed.toFloat();
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return a > b ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
	return a < b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	return a > b ? a : b;
}