/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:09:34 by lucho             #+#    #+#             */
/*   Updated: 2026/10/13 20:36:54 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{}

Intern::Intern(Intern const &other)
{
	(void)other;
}

Intern& Intern::operator=(Intern const &other)
{
	(void) other;
	return(*this);
}

Intern::~Intern(void)
{}

AForm* Intern::createPresidential(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomy(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubbery(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return("form does not exist");
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string const	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm *(Intern::*creators[3])(std::string const &) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	std::cout << "Intern could not create \"" << formName
		<< "\" because this form does not exist." << std::endl;
	
	throw Intern::FormNotFoundException();
}
