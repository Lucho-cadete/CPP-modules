/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 21:09:36 by lucho             #+#    #+#             */
/*   Updated: 2026/10/13 19:35:26 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
	private:
		AForm *createPresidential(std::string const &target) const;
		AForm *createRobotomy(std::string const &target) const;
		AForm *createShrubbery(std::string const &target) const;
	public:
		Intern(void);
		Intern(Intern const &other);
		Intern &operator=(Intern const &other);
		~Intern(void);

		AForm *makeForm(std::string const &formName, std::string const &target) const;
};