/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:41:01 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 14:57:01 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	name = "";
}

Zombie::Zombie(std::string zombieName)
{
	name = zombieName;
}

Zombie::~Zombie()
{
	std::cout << name << " has been destroyed" << std::endl; 
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName)
{
	name = zombieName;
}
