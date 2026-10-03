/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:29:49 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:46:56 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : AAnimal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &other) : AAnimal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

Cat& Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
    return _brain;
}

