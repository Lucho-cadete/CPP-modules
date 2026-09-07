/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:49:52 by lucho             #+#    #+#             */
/*   Updated: 2026/09/07 00:11:42 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string humanName, Weapon &humanWeapon): weapon(humanWeapon)
{
	name = humanName;
}

void HumanA::attack(void) const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
