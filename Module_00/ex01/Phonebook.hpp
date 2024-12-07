/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:48:34 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/07 00:49:40 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Contact.hpp"

class Phonebook {
    public:
        Phonebook();
        ~Phonebook();
        void addContact();
        void searchContact();
    private:
        Contact contacts[8];
        int contactsCount;
};