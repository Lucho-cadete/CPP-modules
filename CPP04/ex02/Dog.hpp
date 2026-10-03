/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:59 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:40:25 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(Dog const &other);
		Dog& operator=(Dog const &other);
		~Dog(void);

		void makeSound(void) const;
		Brain *getBrain(void) const;
};
