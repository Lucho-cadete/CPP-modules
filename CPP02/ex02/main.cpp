/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:13:23 by lucho             #+#    #+#             */
/*   Updated: 2026/09/21 20:56:39 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	Fixed a(5);
	Fixed b(-5);
	Fixed c(2);
	Fixed zero(0);

	std::cout << "--- operaciones normales ---" << std::endl;
	std::cout << "5 + 2  = " << (a + c) << std::endl;
	std::cout << "5 - 2  = " << (a - c) << std::endl;
	std::cout << "5 * 2  = " << (a * c) << std::endl;
	std::cout << "5 / 2  = " << (a / c) << std::endl;

	std::cout << "--- division por cero ---" << std::endl;
	std::cout << "5 / 0  = " << (a / zero) << std::endl;
	std::cout << "-5 / 0 = " << (b / zero) << std::endl;
	std::cout << "0 / 0  = " << (zero / zero) << std::endl;

	std::cout << "--- fin ---" << std::endl;
	return (0);
}