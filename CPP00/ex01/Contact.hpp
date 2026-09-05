/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 22:42:05 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 13:07:14 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;	
	
	public:
		void setFirstName (std::string name);
		std::string getFirstName() const;
		
		void setLastName(std::string name);
        std::string getLastName() const;

        void setNickname(std::string name);
        std::string getNickname() const;

        void setPhoneNumber(std::string number);
        std::string getPhoneNumber() const;

        void setDarkestSecret(std::string secret);
        std::string getDarkestSecret() const;
		
};

#endif