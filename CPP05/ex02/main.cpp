/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:26:42 by lucho             #+#    #+#             */
/*   Updated: 2026/10/12 20:57:01 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <ctime>
#include <cstdlib>


int main(void)
{
	std::srand(std::time(NULL));

	std::cout << "\n=== PresidentialPardon ===" << std::endl;
	
	std::cout << "--- 1. Everything ok ---" << std::endl;
	{
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm p("Arthur");
		b.signForm(p);
		b.executeForm(p);
	}
	std::cout << "\n--- 2. Not signed ---" << std::endl;
	{
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm p("Arthur");
		b.executeForm(p);
	}

	std::cout << "\n--- 3. Grade too low to execute ---" << std::endl;
	{
		Bureaucrat b("Middle", 10);
		PresidentialPardonForm p("Arthur");
		b.signForm(p);
		b.executeForm(p);
	}

	std::cout << "\n--- 4. Exact grade to execute (5) ---" << std::endl;
	{
		Bureaucrat b("Exact", 5);
		PresidentialPardonForm p("Arthur");
		b.signForm(p);
		b.executeForm(p);
	}

	std::cout << "\n--- 5. One grade below execute limit (6) ---" << std::endl;
	{
		Bureaucrat b("Almost", 6);
		PresidentialPardonForm p("Arthur");
		b.signForm(p);
		b.executeForm(p);
	}

	std::cout << "\n--- 6. Exact grade to sign (25) and one below (26) ---" << std::endl;
	{
		Bureaucrat ok("Signer", 25);
		Bureaucrat ko("Clerk", 26);
		PresidentialPardonForm p1("Arthur");
		PresidentialPardonForm p2("Ford");
		ok.signForm(p1);
		ko.signForm(p2);
		std::cout << p1 << std::endl;
		std::cout << p2 << std::endl;
	}

	std::cout << "\n--- 7. Not signed AND grade too low ---" << std::endl;
	{
		Bureaucrat b("Intern", 150);
		PresidentialPardonForm p("Arthur");
		b.executeForm(p);
	}

	std::cout << "\n--- 8. Execute twice ---" << std::endl;
	{
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm p("Arthur");
		b.signForm(p);
		b.executeForm(p);
		b.executeForm(p);
	}

	std::cout << "\n--- 9. Copy constructor ---" << std::endl;
	{
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm p1("Arthur");
		b.signForm(p1);
		PresidentialPardonForm p2(p1);
		std::cout << p2 << std::endl;
		b.executeForm(p2);
	}

	std::cout << "\n--- 10. Assignment operator ---" << std::endl;
	{
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm p1("Arthur");
		PresidentialPardonForm p2("Ford");
		b.signForm(p1);
		p2 = p1;
		std::cout << p2 << std::endl;
		b.executeForm(p2);
	}

	std::cout << "\n--- 11. Invalid bureaucrats ---" << std::endl;
	try
	{
		Bureaucrat b("Bad", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b("Bad", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	
	// std::cout << "\n========== ROBOTOMY REQUEST (sign 72 / exec 45) ==========" << std::endl;
 
	// std::cout << "\n--- R1. Everything ok ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	RobotomyRequestForm r("Bender");
	// 	std::cout << r << std::endl;
	// 	b.signForm(r);
	// 	b.executeForm(r);
	// }
 
	// std::cout << "\n--- R2. Not signed ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	RobotomyRequestForm r("Bender");
	// 	b.executeForm(r);
	// }
 
	// std::cout << "\n--- R3. Can sign (50 <= 72) but not execute (50 > 45) ---" << std::endl;
	// {
	// 	Bureaucrat b("Middle", 50);
	// 	RobotomyRequestForm r("Bender");
	// 	b.signForm(r);
	// 	b.executeForm(r);
	// }
 
	// std::cout << "\n--- R4. Exact grade to execute (45) ---" << std::endl;
	// {
	// 	Bureaucrat b("Exact", 45);
	// 	RobotomyRequestForm r("Bender");
	// 	b.signForm(r);
	// 	b.executeForm(r);
	// }
 
	// std::cout << "\n--- R5. One grade below execute limit (46) ---" << std::endl;
	// {
	// 	Bureaucrat b("Almost", 46);
	// 	RobotomyRequestForm r("Bender");
	// 	b.signForm(r);
	// 	b.executeForm(r);
	// }
 
	// std::cout << "\n--- R6. Exact grade to sign (72) and one below (73) ---" << std::endl;
	// {
	// 	Bureaucrat ok("Signer", 72);
	// 	Bureaucrat ko("Clerk", 73);
	// 	RobotomyRequestForm r1("Bender");
	// 	RobotomyRequestForm r2("Marvin");
	// 	ok.signForm(r1);
	// 	ko.signForm(r2);
	// 	std::cout << r1 << std::endl;
	// 	std::cout << r2 << std::endl;
	// }
 
	// std::cout << "\n--- R7. 50% success: execute 6 times ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	RobotomyRequestForm r("Bender");
	// 	b.signForm(r);
	// 	for (int i = 0; i < 6; i++)
	// 	{
	// 		std::cout << "\n[attempt " << i + 1 << "]" << std::endl;
	// 		b.executeForm(r);
	// 	}
	// }
 
	
	// std::cout << "\n=== SHRUBBERY ===" << std::endl;

	// std::cout << "\n--- S1. Everything ok ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	ShrubberyCreationForm s("home");
	// 	b.signForm(s);
	// 	b.executeForm(s);
	// }

	// std::cout << "\n--- S2. Not signed ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	ShrubberyCreationForm s("garden");
	// 	b.executeForm(s);
	// }

	// std::cout << "\n--- S3. Can sign (145) but not execute (137) ---" << std::endl;
	// {
	// 	Bureaucrat b("Gardener", 140);
	// 	ShrubberyCreationForm s("park");
	// 	b.signForm(s);
	// 	b.executeForm(s);
	// }

	// std::cout << "\n--- S4. Exact grade to execute (137) ---" << std::endl;
	// {
	// 	Bureaucrat b("Exact", 137);
	// 	ShrubberyCreationForm s("exact");
	// 	b.signForm(s);
	// 	b.executeForm(s);
	// }

	// std::cout << "\n--- S5. Exact grade to sign (145) and one below (146) ---" << std::endl;
	// {
	// 	Bureaucrat ok("Signer", 145);
	// 	Bureaucrat ko("Clerk", 146);
	// 	ShrubberyCreationForm s1("a");
	// 	ShrubberyCreationForm s2("b");
	// 	ok.signForm(s1);
	// 	ko.signForm(s2);
	// }

	// std::cout << "\n--- S6. File cannot be opened ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	ShrubberyCreationForm s("noexiste/home");
	// 	b.signForm(s);
	// 	b.executeForm(s);
	// }

	// std::cout << "\n--- S7. Execute twice, same target ---" << std::endl;
	// {
	// 	Bureaucrat b("Boss", 1);
	// 	ShrubberyCreationForm s("twice");
	// 	b.signForm(s);
	// 	b.executeForm(s);
	// 	b.executeForm(s);
	// }

	return (0);
}