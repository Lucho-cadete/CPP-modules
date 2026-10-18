/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:02 by lucho             #+#    #+#             */
/*   Updated: 2026/10/18 18:52:36 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <limits>
#include <cctype>
#include <string>
#include <stdexcept>

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

static std::string	formatNumber(double value)
{
	std::ostringstream	out;

	out << value;
	std::string	text = out.str();
	if (text.find('.') == std::string::npos && text.find('e') == std::string::npos)
		text += ".0";
	return (text);
}

static void	printChar(double value)
{
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char	c = static_cast<char>(value);
	if (!std::isprint(static_cast<int>(c)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;
}

static void	printInt(double value)
{
	std::cout << "int: ";
	if (std::isnan(value)
		|| value < static_cast<double>(std::numeric_limits<int>::min())
		|| value > static_cast<double>(std::numeric_limits<int>::max()))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	std::cout << "float: ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
		return ;
	}
	if (value > static_cast<double>(std::numeric_limits<float>::max())
		|| value < -static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	float	f = static_cast<float>(value);
	std::cout << formatNumber(static_cast<double>(f)) << "f" << std::endl;
}

static void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
		return ;
	}
	std::cout << formatNumber(value) << std::endl;
}

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
				break;
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
