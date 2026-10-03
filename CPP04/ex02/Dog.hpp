/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:59 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 16:17:49 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Aanimal.hpp"
#include "Brain.hpp"

class Dog : public Aanimal{
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
