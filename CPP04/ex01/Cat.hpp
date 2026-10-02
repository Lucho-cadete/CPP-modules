/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:53 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 11:16:46 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat(void);
		Cat(Cat const &other);
		Cat& operator=(Cat const &other);
		~Cat(void);

		void makeSound(void) const;
};
