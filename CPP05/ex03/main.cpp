/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:26:42 by lucho             #+#    #+#             */
/*   Updated: 2026/10/13 19:20:31 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <cstdlib>
#include <ctime>

static void	testIntern(Intern const &intern, Bureaucrat &boss,
				std::string const &formName, std::string const &target)
{
	AForm	*form = NULL;

	std::cout << "\n--- makeForm(\"" << formName << "\", \"" << target << "\") ---" << std::endl;
	try
	{
		form = intern.makeForm(formName, target);
		if (form == NULL)
			return ;
		std::cout << *form << std::endl;
		boss.signForm(*form);
		boss.executeForm(*form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	delete form;
}

int	main(void)
{
	std::srand(std::time(NULL));

	try
	{
		Intern		intern;
		Bureaucrat	boss("Boss", 1);
		Bureaucrat	clerk("Clerk", 140);

		std::cout << "========== VALID NAMES ==========" << std::endl;
		testIntern(intern, boss, "shrubbery creation", "home");
		testIntern(intern, boss, "robotomy request", "Bender");
		testIntern(intern, boss, "presidential pardon", "Arthur");

		std::cout << "\n========== INVALID NAMES ==========" << std::endl;
		testIntern(intern, boss, "coffee request", "Boss");
		testIntern(intern, boss, "Robotomy Request", "Bender");
		testIntern(intern, boss, "", "nobody");

		std::cout << "\n========== LOW GRADE BUREAUCRAT ==========" << std::endl;
		testIntern(intern, clerk, "shrubbery creation", "garden");
		testIntern(intern, clerk, "presidential pardon", "Ford");

		std::cout << "\n========== SUBJECT EXAMPLE ==========" << std::endl;
		{
			Intern	someRandomIntern;
			AForm	*rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			if (rrf)
			{
				boss.signForm(*rrf);
				boss.executeForm(*rrf);
				delete rrf;
				rrf = NULL;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}