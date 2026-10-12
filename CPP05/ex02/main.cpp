/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:26:42 by lucho             #+#    #+#             */
/*   Updated: 2026/10/12 18:27:30 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
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

	return (0);
}