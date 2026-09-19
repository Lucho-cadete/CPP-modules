/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 23:00:56 by lucho             #+#    #+#             */
/*   Updated: 2026/09/19 15:44:15 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed (void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed (int const value)
{
	std::cout << "Int constructor called" << std::endl;
	int const scale = 1 << _fractionalBits;
	
	if (value > 8388607)
		_value = 2147483647;
	else if (value < -8388608)
		_value = -2147483648;
	else
		_value = value * scale;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	int const scale = 1 << _fractionalBits;
	float const scaled = value * scale;

	if (scaled != scaled)
		_value = 0;
	else if (scaled > 2147483647.0f)
		_value = 2147483647;
	else if (scaled < -2147483648.0f)
		_value = -2147483648;
	else
		_value = roundf(scaled);
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_value = other._value;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits (void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt (void) const
{
	return (_value / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}
