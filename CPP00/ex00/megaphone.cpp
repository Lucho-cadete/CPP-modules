/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 22:16:21 by lucho             #+#    #+#             */
/*   Updated: 2026/08/07 23:12:50 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string arg = argv[i];
			for (int j = 0; j < (int)arg.length(); j++)
			{
				char uppercase = static_cast<char>(std::toupper(arg[j]));
				std::cout << uppercase;
			}
		}
	}
	std::cout << std::endl;
	return(0);
}