/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:42:02 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 13:08:32 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName(std::string name)
{
    firstName = name;
}

std::string Contact::getFirstName() const
{
    return (firstName);
}

void Contact::setLastName(std::string name)
{
    lastName = name;
}

std::string Contact::getLastName() const
{
    return (lastName);
}

void Contact::setNickname(std::string name)
{
    nickname = name;
}

std::string Contact::getNickname() const
{
    return (nickname);
}

void Contact::setPhoneNumber(std::string number)
{
    phoneNumber = number;
}

std::string Contact::getPhoneNumber() const
{
    return (phoneNumber);
}

void Contact::setDarkestSecret(std::string secret)
{
    darkestSecret = secret;
}

std::string Contact::getDarkestSecret() const
{
    return (darkestSecret);
}
