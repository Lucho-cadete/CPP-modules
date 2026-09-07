/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:49:49 by lucho             #+#    #+#             */
/*   Updated: 2026/09/07 00:04:52 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    private:
		std::string name;
    	Weapon &weapon;
    public:
		HumanA(std::string humanName, Weapon &humanWeapon);
		void attack(void) const;
};

#endif