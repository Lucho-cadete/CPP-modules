/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:49:44 by lucho             #+#    #+#             */
/*   Updated: 2026/09/07 00:18:09 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB {
    private:
		std::string name;
		Weapon *weapon;
    public:
		HumanB(std::string humanName);
		void setWeapon(Weapon &newWeapon);
		void attack(void) const;
};

#endif
