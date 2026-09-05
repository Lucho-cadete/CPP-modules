/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 23:36:27 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 13:25:05 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main()
{
    PhoneBook pb;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH or EXIT): ";
        std::cin >> command;
        std::cin.ignore();

        if (command == "ADD")
        {
            Contact newContact;
            std::string input;

            do
            {
                std::cout << "First name: ";
                std::getline(std::cin, input);
            }
            while (input.empty());
            newContact.setFirstName(input);

            do
            {
                std::cout << "Last name: ";
                std::getline(std::cin, input);
            }
            while (input.empty());
            newContact.setLastName(input);

            do
            {
                std::cout << "Nickname: ";
                std::getline(std::cin, input);
            }
            while (input.empty());
            newContact.setNickname(input);

            do
            {
                std::cout << "Phone number: ";
                std::getline(std::cin, input);
            }
            while (input.empty());
            newContact.setPhoneNumber(input);

            do
            {
                std::cout << "Darkest secret: ";
                std::getline(std::cin, input);
            }
            while (input.empty());
            newContact.setDarkestSecret(input);

            pb.addContact(newContact);
        }
        else if (command == "SEARCH")
        {
            pb.showAllContacts();

            int index;
            std::cout << "Enter index: ";
            std::cin >> index;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Invalid index." << std::endl;
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                pb.showContact(index);
            }
        }
        else if (command == "EXIT")
            break;
    }
    return (0);
}
