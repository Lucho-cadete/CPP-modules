/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:13:11 by lucho             #+#    #+#             */
/*   Updated: 2026/09/23 12:24:02 by lucho            ###   ########.fr       */
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

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	int const scale = 1 << _fractionalBits;

	if (value > 8388607)
	{
		std::cerr << "Warning: value out of range, saturated to max" << std::endl;
		this->_value = 2147483647;
	}
	else if (value < -8388608)
	{
		std::cerr << "Warning: value out of range, saturated to min" << std::endl;
		this->_value = -2147483648;
	}
	else
		this->_value = value * scale;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	int const scale = 1 << _fractionalBits;
	float const scaled = value * scale;

	if (scaled != scaled)
	{
		std::cerr << "Warning: invalid value (NaN), set to 0" << std::endl;
		this->_value = 0;
	}
	else if (scaled > 2147483647.0f)
	{
		std::cerr << "Warning: value out of range, saturated to max" << std::endl;
		this->_value = 2147483647;
	}
	else if (scaled < -2147483648.0f)
	{
		std::cerr << "Warning: value out of range, saturated to min" << std::endl;
		this->_value = -2147483648;
	}
	else
		this->_value = roundf(scaled);
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

std::ostream& operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

bool Fixed::operator> (Fixed const &other) const
{
	if (_value > other._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator< (Fixed const &other) const
{
	if (_value < other._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator>= (Fixed const &other) const
{
	if (_value >= other._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator<= (Fixed const &other) const
{
	if (_value <= other._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator== (Fixed const &other) const
{
	if (_value == other._value)
		return (true);
	else
		return (false);
}

bool Fixed::operator!= (Fixed const &other) const
{
	if (_value != other._value)
		return (true);
	else
		return (false);
}

Fixed Fixed::operator+(Fixed const &other) const
{
	Fixed result;

	if (other._value > 0 && this->_value > 2147483647 - other._value)
	{
		std::cerr << "Warning: addition overflow, saturated to max" << std::endl;
		result._value = 2147483647;
	}
	else if (other._value < 0 && this->_value < -2147483648 - other._value)
	{
		std::cerr << "Warning: addition overflow, saturated to min" << std::endl;
		result._value = -2147483648;
	}
	else
		result._value = this->_value + other._value;
	return (result);
}

Fixed Fixed::operator-(Fixed const &other) const
{
	Fixed result;

	if (other._value < 0 && this->_value > 2147483647 + other._value)
	{
		std::cerr << "Warning: subtraction overflow, saturated to max" << std::endl;
		result._value = 2147483647;
	}
	else if (other._value > 0 && this->_value < -2147483648 + other._value)
	{
		std::cerr << "Warning: subtraction overflow, saturated to min" << std::endl;
		result._value = -2147483648;
	}
	else
		result._value = this->_value - other._value;
	return (result);
}

Fixed Fixed::operator*(Fixed const &other) const
{
	float left = this->toFloat();
	float right = other.toFloat();
	float product = left * right;
	Fixed result(product);
	return (result);
}

Fixed Fixed::operator/(Fixed const &other) const
{
	float left = this->toFloat();
	float right = other.toFloat();
	float division = left / right;
	Fixed result(division);
	return(result);
}

Fixed &Fixed::operator++(void)
{
	if (this->_value == 2147483647)
		std::cerr << "Warning: increment overflow, value unchanged" << std::endl;
	else
		this->_value = this->_value + 1;
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	if (this->_value == -2147483648)
		std::cerr << "Warning: decrement overflow, value unchanged" << std::endl;
	else
		this->_value = this->_value - 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed original(*this);

	if (this->_value == 2147483647)
		std::cerr << "Warning: increment overflow, value unchanged" << std::endl;
	else
		this->_value = this->_value + 1;
	return (original);
}

Fixed Fixed::operator--(int)
{
	Fixed original(*this);
	if (this->_value == -2147483648)
		std::cerr << "Warning: decrement overflow, value unchanged" << std::endl;
	else
		this->_value = this->_value - 1;
	return (original);
}