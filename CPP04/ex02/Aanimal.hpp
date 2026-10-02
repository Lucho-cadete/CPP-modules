/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:31:30 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 13:22:17 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Aanimal{
	protected:
		std::string	type;

	public:
		Aanimal(void);
		Aanimal(Animal const &other);
		Aanimal& operator=(Aanimal const &other);
		virtual ~Aanimal(void);

		virtual void makeSound(void) const;
		std::string getType(void) const;
};
