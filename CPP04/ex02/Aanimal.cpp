/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:22:07 by lucho             #+#    #+#             */
/*   Updated: 2026/10/02 13:22:53 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Aanimal.hpp"
#include <iostream>

Aanimal::Aanimal(void)
{
	std::cout << "Aanimal default constructor called" << std::endl;
	this->type = "Aanimal";
}

Aanimal::Aanimal(Aanimal const &other)
{
	std::cout << "Aanimal copy constructor called" << std::endl;
	this->type = other.type;
}

Aanimal& Aanimal::operator=(Aanimal const &other)
{
	std::cout << "Aanimal copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

Aanimal::~Aanimal(void)
{
	std::cout << "Aanimal destructor called" << std::endl;
}

void Aanimal::makeSound(void) const
{
	std::cout << "* some generic Aanimal noise *" << std::endl;
}

std::string Aanimal::getType(void) const
{
	return (this->type);
}
