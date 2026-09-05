/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:41:59 by lucho             #+#    #+#             */
/*   Updated: 2026/09/05 15:02:14 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "zombieHorde.hpp"

int main()
{
	long int numofzombies = 3;
	Zombie *horde = zombieHorde(numofzombies, "");

	for (int i = 0; i < numofzombies; i++)
		horde[i].announce();
	
	delete [] horde;
	return (0);
}