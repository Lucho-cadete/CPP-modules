/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:31:30 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:56:46 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class AAnimal{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const &other);
		AAnimal& operator=(AAnimal const &other);
		virtual ~AAnimal(void);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};
