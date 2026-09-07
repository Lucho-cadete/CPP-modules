/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 15:48:18 by lucho             #+#    #+#             */
/*   Updated: 2026/09/07 00:27:56 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
    type = weaponType;
}

void Weapon::setType(std::string newType)
{
	type = newType;
}

const std::string& Weapon::getType() const
{
	return (type);
}
