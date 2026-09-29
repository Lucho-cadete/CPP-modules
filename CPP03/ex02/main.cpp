/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:04:35 by lucho             #+#    #+#             */
/*   Updated: 2026/09/29 10:26:30 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "=== the three classes side by side ===" << std::endl;
	{
		ClapTrap clap("Clap");
		ScavTrap scav("Scav");
		FragTrap frag("Frag");

		std::cout << std::endl << "=== attack: 0 / 20 / 30 damage ===" << std::endl;
		clap.attack("target");
		scav.attack("target");
		frag.attack("target");

		std::cout << std::endl << "=== special abilities ===" << std::endl;
		scav.guardGate();
		frag.highFivesGuys();

		std::cout << std::endl << "=== destruction: reverse creation order ===" << std::endl;
	}

	std::cout << std::endl << "=== FragTrap: 100 hit points, 100 energy ===" << std::endl;
	FragTrap frag("Frag");
	frag.takeDamage(60);
	frag.beRepaired(40);

	std::cout << std::endl << "=== out of energy (100 actions) ===" << std::endl;
	FragTrap tired("Tired");
	for (int i = 0; i < 101; i++)
		tired.attack("nobody");

	std::cout << std::endl << "=== orthodox canonical form ===" << std::endl;
	FragTrap byDefault;
	FragTrap copy(frag);
	FragTrap assigned;
	assigned = frag;

	std::cout << std::endl << "=== destructors ===" << std::endl;
	return (0);
}