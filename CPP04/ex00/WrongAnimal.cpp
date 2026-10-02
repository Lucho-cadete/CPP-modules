/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:40:27 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 11:21:03 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
{
	std::cout << "Default WrongAnimal constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &other)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->type = other.type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "* some WRONG generic Animal noise *" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}
