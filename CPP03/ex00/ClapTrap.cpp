/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 12:59:57 by lucho             #+#    #+#             */
/*   Updated: 2026/09/23 23:57:18 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string const &name)
{
	std::cout << "ClapTrap " << name << " constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " can't attack: no hit points or energy left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already destroyed!" << std::endl;
		return ;
	}
	if (amount >= (unsigned int)this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
			  << " points of damage! Hit points left: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name
				  << " can't be repaired: no hit points or energy left!" << std::endl;
		return ;
	}
	this->_energyPoints--;
	if (amount > (unsigned int)(2147483647 - this->_hitPoints))
		this->_hitPoints = 2147483647;
	else
		this->_hitPoints += amount;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount
			  << " points! Hit points: " << this->_hitPoints << std::endl;
}
