/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:02 by lucho             #+#    #+#             */
/*   Updated: 2026/10/17 08:47:22 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <limits>

enum e_type
{
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

static bool	isPseudoFloat(std::string const &str)
{
	return (str == "nanf" || str == "+inff" || str == "-inff");
}

static bool	isPseudoDouble(std::string const &str)
{
	return (str == "nan" || str == "+inf" || str == "-inf");
}

static bool	isChar(std::string const &str)
{
	return (str.length() == 1 && !std::isdigit(str[0]));
}

static bool	isInt(std::string const &str)
{
	size_t	i = 0;

	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
		i = 1;
	if (i == str.length())
		return (false);
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

static e_type	floatOrDouble(std::string const &str)
{
	size_t	i = 0;
	size_t	start;

	if (!str.empty() && (str[0] == '+' || str[0] == '-'))
		i = 1;
	start = i;
	while (i < str.length() && std::isdigit(str[i]))
		i++;
	if (i == start)
		return (TYPE_INVALID);
	if (i == str.length() || str[i] != '.')
		return (TYPE_INVALID);
	i++;
	start = i;
	while (i < str.length() && std::isdigit(str[i]))
		i++;
	if (i == start)
		return (TYPE_INVALID);
	if (i == str.length())
		return (TYPE_DOUBLE);
	if (str[i] == 'f' && i + 1 == str.length())
		return (TYPE_FLOAT);
	return (TYPE_INVALID);
}

static e_type	detectType(std::string const &str)
{
	if (isPseudoFloat(str))
		return (TYPE_FLOAT);
	if (isPseudoDouble(str))
		return (TYPE_DOUBLE);
	if (isChar(str))
		return (TYPE_CHAR);
	if (isInt(str))
		return (TYPE_INT);
	return (floatOrDouble(str));
}

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return(*this);
}
ScalarConverter::~ScalarConverter(void)
{}

void	ScalarConverter::convert(std::string const &literal)
{
	e_type	type = detectType(literal);
	double value;
	
	try
	{
		switch (type)
		{
			case TYPE_CHAR:
			{
				char c = literal[0];
				value = static_cast<double>(c);
				break;
			}
			case TYPE_INT:
			{
				int n = std::stoi(literal);
				value = static_cast<double>(n);
				break;
			}
			case TYPE_FLOAT:
			{
				float f = std::stof(literal);
				value = static_cast<double>(f);
				break
			}
			case TYPE_DOUBLE:
			{
				double d = std::stod(literal);
				value = d;
				break;
			}
			default:
				std::cout << "Error: Invalid literal" << std::endl;
				return;
		}
	}
	catch (std::out_of_range const &e)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);	
}
