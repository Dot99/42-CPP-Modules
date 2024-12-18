/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/17 08:44:45 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <cmath>

class Fixed{
	public:
		// Default constructor
		Fixed();
		// Parameterized constructor
		Fixed(const int value);
		// Parameterized constructor
		Fixed(const float value);
		// Copy constructor
		Fixed(Fixed const &src);
		// Destructor
		~Fixed();
		// Assignment operator
		Fixed &operator=(Fixed const &fixed);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _value;
		static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);