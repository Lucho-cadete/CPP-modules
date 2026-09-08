/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luimarti <luimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 12:08:26 by luimarti          #+#    #+#             */
/*   Updated: 2026/09/08 13:24:02 by luimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceAll(std::string text, std::string s1, std::string s2)
{
    std::string result = "";
    size_t pos = 0;
    size_t encontrado = text.find(s1, pos);

    while (encontrado != std::string::npos)
    {
        result += text.substr(pos, encontrado - pos);
        result += s2;
        pos = encontrado + s1.length();
        encontrado = text.find(s1, pos);
    }
    result += text.substr(pos);
    return (result);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: usage is ./program <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
	if (s1 == "")
	{
		std::cout << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
		std::string s2 = argv[3];

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }

	std::ostringstream buffer;
	buffer << inputFile.rdbuf();
	std::string content = buffer.str();
	inputFile.close();
	std::string result = replaceAll(content, s1, s2);
	std::string outputFilename = filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open())
    {
        std::cout << "Error: could not open file" << std::endl;
        return (1);
    }
	outputFile << result;
	outputFile.close();
    return (0);
}
