/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 11:39:49 by lucho             #+#    #+#             */
/*   Updated: 2026/10/03 17:34:43 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for(int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(Brain const &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for(int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, std::string const &idea)
{
	if (index < 0 || index > 99)
		return ;
	this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return ("");
	return(this->ideas[index]);
}
