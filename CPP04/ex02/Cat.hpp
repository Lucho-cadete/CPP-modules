/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:53 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 13:23:39 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Aanimal.hpp"
#include "Brain.hpp"

class Cat : public Aanimal{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat const &other);
		Cat& operator=(Cat const &other);
		~Cat(void);

		void makeSound(void) const;
		Brain *getBrain(void);
};
