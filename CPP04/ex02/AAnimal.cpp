/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 17:33:17 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:37:43 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(AAnimal const &other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	this->type = other.type;
}

AAnimal& AAnimal::operator=(AAnimal const &other)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}
