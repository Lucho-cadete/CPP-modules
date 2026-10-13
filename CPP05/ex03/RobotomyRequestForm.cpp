/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 18:39:08 by lucho             #+#    #+#             */
/*   Updated: 2026/10/12 18:44:26 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void)
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
	: AForm(other), _target(other._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "  ____" << std::endl;
	std::cout << " |    |=====------  WIIIIIIIIIIINGGG!!!" << std::endl;
	std::cout << " |____|" << std::endl;
	std::cout << "   ||" << std::endl;
	std::cout << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << "   [o_o]" << std::endl;
		std::cout << "  /|___|\\" << std::endl;
		std::cout << "   /   \\" << std::endl;
		std::cout << this->_target << " has been robotomized successfully!"
			<< std::endl;
	}
	else
	{
		std::cout << "   _____" << std::endl;
		std::cout << "  /     \\" << std::endl;
		std::cout << " | () () |" << std::endl;
		std::cout << "  \\  ^  /" << std::endl;
		std::cout << "   |||||" << std::endl;	
		std::cout << "The robotomy of " << this->_target << " failed." <<std::endl;
	}
}	
