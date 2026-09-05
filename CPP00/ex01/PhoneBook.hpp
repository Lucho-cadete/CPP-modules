/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 22:48:03 by lucho             #+#    #+#             */
/*   Updated: 2026/09/02 12:48:34 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook{
	private: 
		Contact contacts[8];
    	int contactCount;
		int getContactMax();
	public:
		PhoneBook();
		void addContact(Contact newContact);
        void showAllContacts();
        void showContact(int index);
};

#endif