/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 23:05:50 by lucho             #+#    #+#             */
/*   Updated: 2026/09/04 00:20:05 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook()
{
    contactCount = 0;
}

void PhoneBook::addContact(Contact newContact)
{
	int position;
	
	position = contactCount % 8;
	contacts[position] = newContact;
	contactCount++;
	
}

std::string formatColumn(std::string text)
{
    if (text.length() > 10)
        return (text.substr(0, 9) + ".");
    return (text);
}

int PhoneBook::getContactMax()
{
    if (contactCount < 8)
        return (contactCount);
    return (8);
}

void PhoneBook::showAllContacts()
{
    int max = getContactMax();

    for (int i = 0; i < max; i++)
    {
		std::cout << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << formatColumn(contacts[i].getFirstName()) << "|";
		std::cout << std::right << std::setw(10) << formatColumn(contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << formatColumn(contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::showContact(int index)
{
	int max = getContactMax();

    if (index >= 0 && index < max)
    {
        std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
		std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
    }
	else
		std::cout << "Error: Index invalid!" << std::endl;
}
