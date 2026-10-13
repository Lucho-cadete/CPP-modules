/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:52:11 by lucho             #+#    #+#             */
/*   Updated: 2026/10/12 20:21:39 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
	: AForm(other), _target(other._target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

const char* ShrubberyCreationForm::FileImpossibleToOpenException::what() const throw()
{
	return("File could not be opened");
}

void ShrubberyCreationForm::executeAction() const
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file(fileName);
	if (!file.is_open())
		throw ShrubberyCreationForm::FileImpossibleToOpenException();
	file << "      /\\            /\\            /\\" << std::endl;
	file << "     /**\\          /**\\          /**\\" << std::endl;
	file << "    /****\\        /****\\        /****\\" << std::endl;
	file << "   /******\\      /******\\      /******\\" << std::endl;
	file << "  /********\\    /********\\    /********\\" << std::endl;
	file << " /**********\\  /**********\\  /**********\\" << std::endl;
	file << "      ||            ||            ||" << std::endl;
	file << "      ||            ||            ||" << std::endl;	
}
