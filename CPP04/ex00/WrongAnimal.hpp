/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:39:44 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 11:19:09 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &other);
		WrongAnimal& operator=(WrongAnimal const &other);
		virtual ~WrongAnimal(void);

		void makeSound(void) const;
		std::string getType(void) const;
};
