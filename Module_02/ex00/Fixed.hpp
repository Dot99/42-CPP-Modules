/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:49:01 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/13 12:18:58 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Fixed{
	public:
		//Default constructor
		Fixed();
		//Copy constructor
		Fixed(Fixed const &src);
		//Destructor
		~Fixed();
		//Assignment operator
		Fixed &operator=(Fixed const &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int _value;
		static const int _fractionalBits = 8;
};