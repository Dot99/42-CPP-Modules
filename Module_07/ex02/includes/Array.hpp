/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:57:00 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/16 14:23:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

template <typename T>

class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        //Default Constructor
        Array(void) : _array(new T[0]), _size(0) {
            std::cout << "Default constructor called" << std::endl;
        }
        // Constructor with size
        Array(unsigned int n) : _array(new T[n]), _size(n) {
            std::cout << "Constructor with size called" << std::endl;
        }
        //Copy Constructor
        Array(Array const &src) : _array(new T[src._size]), _size(src._size)
        {
            std::cout << "Copy constructor called" << std::endl;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = src._array[i];
        }
        //Destructor
        ~Array(void) {
            std::cout << "Destructor called" << std::endl;
            delete [] _array;
        }
        //Assignment operator
        Array &operator=(Array const &src)
        {
            std::cout << "Assignment operator called" << std::endl;
            if (this != &src)
            {
                delete [] _array;
                _array = new T[src._size];
                _size = src._size;
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = src._array[i];
            }
            return *this;
        }
        //Operator []
        T &operator[](unsigned int i)
        {
            if (i >= _size || _array == NULL)
            {
                throw Array<T>::OutOfRangeException();
            }
            if (i >= _size)
            {
                throw Array<T>::OutOfRangeException();
            }
            return _array[i];
        }
        unsigned int size(void) const {
            std::cout << "Size called" << std::endl;
            return _size;
        }
        //Exception class
        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

template <typename T>

const char *Array<T>::OutOfRangeException::what() const throw()
{
    return "Index out of range";
}