/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:31:30 by lucho             #+#    #+#             */
/*   Updated: 2026/09/30 13:52:04 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Animal{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(Animal const &other);
		Animal& operator=(Animal const &other);
		virtual ~Animal(void);

		virtual void makeSound(void) const;
		std::string getType(void) const;
};
