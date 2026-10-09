/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 10:26:42 by lucho             #+#    #+#             */
/*   Updated: 2026/10/09 17:00:47 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{
	std::cout << "--- Valid aform ---" << std::endl;
	try
	{
		AForm a("A", 50, 25);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Sign grade 0 ---" << std::endl;
	try
	{
		AForm b("B", 0, 25);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- Execute grade 151 ---" << std::endl;
	try
	{
		AForm c("C", 50, 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- beSigned ---" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 42);
		AForm easy("Easy", 50, 25);
		AForm hard("Hard", 10, 5);

		easy.beSigned(bob);
		std::cout << easy << std::endl;
		hard.beSigned(bob);
		std::cout << hard << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n--- FINAL TEST ---" << std::endl;
	std::cout << "\n--- signAForm ---" << std::endl;
	
	Bureaucrat lucho("Lucho", 21);
	AForm basic("basic", 21, 21);
	AForm demanding("demanding", 1, 1);
	
	lucho.signForm(basic);
	lucho.signForm(demanding);
	std::cout << std::endl;
	std::cout << basic << std::endl;
	std::cout << demanding << std::endl;

	return(0);
}