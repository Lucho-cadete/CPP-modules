/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 10:04:35 by lucho             #+#    #+#             */
/*   Updated: 2026/09/29 10:12:05 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "--- construction chain ---" << std::endl;
	ScavTrap scav("Serena");

	std::cout << "--- own attack message ---" << std::endl;
	scav.attack("Bob");

	std::cout << "--- special ability ---" << std::endl;
	scav.guardGate();

	std::cout << "--- inherited functions ---" << std::endl;
	scav.takeDamage(30);
	scav.beRepaired(10);

	std::cout << "--- a plain ClapTrap for comparison ---" << std::endl;
	ClapTrap clap("Bob");
	clap.attack("Serena");

	std::cout << "--- destruction chain (reverse order) ---" << std::endl;
	return (0);
}