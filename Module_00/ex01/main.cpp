#include "Phonebook.hpp"

int main()
{
    Phonebook phonebook;
    std::string command;

    while(1)
    {
        std::cout << "Enter ADD, SEARCH or EXIT: ";
        if(!std::getline(std::cin, command)){
            if(std::cin.eof())
            {
                std::cout << std::endl;
                break;
            }
            else{
                std::cin.clear();
                std::cin.ignore(10, '\n');
                continue;
            }
        }
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else if (command == "EXIT")
            break;
        else
            std::cout << "Invalid command. Please enter ADD, SEARCH or EXIT." << std::endl;
    }
    return (0);
}