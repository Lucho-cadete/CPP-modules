/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 13:41:09 by lucho             #+#    #+#             */
/*   Updated: 2026/09/30 13:58:02 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal (void)
{
	std::cout << "Default animal constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->type = other.type;
}

Animal& Animal::operator=(Animal const &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "* some generic animal noise *" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->type);
}
