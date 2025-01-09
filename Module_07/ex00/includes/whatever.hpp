/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:38:50 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/09 11:16:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template <typename T>

void swap(T &a,T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename U>

const U &min(const U a,const U b) {
	return (a < b ? a : b);
}

template <typename V>

const V &max(const V a,const V b) {
	return (a > b ? a : b);
}