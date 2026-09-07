/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:49:47 by lucho             #+#    #+#             */
/*   Updated: 2026/09/07 00:18:04 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string humanName)
{
    name = humanName;
    weapon = NULL;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack(void) const
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}