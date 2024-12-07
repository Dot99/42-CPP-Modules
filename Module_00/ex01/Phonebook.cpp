/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 00:46:59 by gude-jes          #+#    #+#             */
/*   Updated: 2024/12/07 01:12:35 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook(){
    this->contactsCount = 0;
}

Phonebook::~Phonebook(){
}

std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    else
        return (str);
}

void Phonebook::addContact(){
    int position = this->contactsCount;
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    std::cout << "Enter first name: " << std::endl;
    std::getline(std::cin, firstName);
    std::cout << "Enter last name: " << std::endl;
    std::getline(std::cin, lastName);
    std::cout << "Enter nickname: " << std::endl;
    std::getline(std::cin, nickname);
    std::cout << "Enter phone number: " << std::endl;
    std::getline(std::cin, phoneNumber);
    std::cout << "Enter darkest secret: " << std::endl;
    std::getline(std::cin, darkestSecret);
    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty())
    {
        std::cout << "Input is invalid, you must fill all fields" << std::endl;
        return;
    }
    this->contactsCount++;
    this->contacts[position].setFirstName(firstName);
    this->contacts[position].setLastName(lastName);
    this->contacts[position].setNickname(nickname);
    this->contacts[position].setPhoneNumber(phoneNumber);
    this->contacts[position].setDarkestSecret(darkestSecret);
}

void Phonebook::searchContact(){
    if(this->contactsCount == 0){
        std::cout << "No contacts available" << std::endl;
        return;
    }
    for(int i = 0; i < 8; i++){
        if(i < this->contactsCount){
            std::cout << std::setw(10) << i << "|";
            std::cout << std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|";
            std::cout << std::setw(10) << truncate(this->contacts[i].getLastName()) << "|";
            std::cout << std::setw(10) << truncate(this->contacts[i].getNickname()) << std::endl;
        }
    }
    std::string index;
    std::cout << "Enter index of the contact you want to see: ";
    std::getline(std::cin, index);
    if(index.length() == 1 && index[0] >= '0' && index[0] <= '7' && index[0] - '0' < this->contactsCount){
        int i = index[0] - '0';
        std::cout << "First name: " << this->contacts[i].getFirstName() << std::endl;
        std::cout << "Last name: " << this->contacts[i].getLastName() << std::endl;
        std::cout << "Nickname: " << this->contacts[i].getNickname() << std::endl;
    }
    else
        std::cout << "Invalid index" << std::endl;
}