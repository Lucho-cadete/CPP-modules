/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:44:57 by lucho             #+#    #+#             */
/*   Updated: 2026/10/16 20:21:50 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc < 2)
			std::cout << "Error: no literal given." << std::endl;
		else
			std::cout << "Error: too many arguments." << std::endl;
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return(0);
}