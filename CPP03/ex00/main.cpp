/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:53:35 by lucho             #+#    #+#             */
/*   Updated: 2026/09/23 23:58:37 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap a("Bob");
	ClapTrap b("Serena");

	std::cout << "--- attacks ---" << std::endl;
	a.attack("Serena");
	b.attack("Bob");

	std::cout << "--- damage and repair ---" << std::endl;
	a.takeDamage(4);
	a.beRepaired(2);

	std::cout << "--- out of hit points ---" << std::endl;
	a.takeDamage(100);
	a.attack("Serena");
	a.beRepaired(5);

	std::cout << "--- out of energy ---" << std::endl;
	ClapTrap c("Tired");
	for (int i = 0; i < 11; i++)
		c.attack("nobody");

	std::cout << "--- orthodox canonical form ---" << std::endl;
	ClapTrap d(b);
	ClapTrap e;
	e = b;

	std::cout << "--- end ---" << std::endl;
	return (0);
}