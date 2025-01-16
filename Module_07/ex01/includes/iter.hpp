/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:29:48 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/16 13:52:47 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cctype>

template <typename T>

void iter(T *array, size_t size, void (*f)(T &))
{
    if (array == NULL || f == NULL)
    {
        return ;
    }
	for (size_t i = 0; i < size; i++)
    {
		f(array[i]);
    }
}
