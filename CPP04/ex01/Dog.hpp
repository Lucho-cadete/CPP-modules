/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:59 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 11:15:41 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(void);
		Dog(Dog const &other);
		Dog& operator=(Dog const &other);
		~Dog(void);

		void makeSound(void) const;
};
