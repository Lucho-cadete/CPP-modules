/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 12:15:22 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 12:59:35 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "randomChump.hpp"
#include "newZombie.hpp"

int main()
{
	Zombie *nat;
	
	randomChump("Lucho");
	nat = newZombie("Nat");
	nat->announce();
	delete nat;
	return (0);
}