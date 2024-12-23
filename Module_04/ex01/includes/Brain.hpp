/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 09:05:53 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/23 11:42:13 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		std::string getIdea(int index) const;
		void setIdea(int index, std::string idea);
};