/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 19:13:18 by lucho             #+#    #+#             */
/*   Updated: 2026/09/23 12:37:38 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
private:
	int _value;
	static const int _fractionalBits;

public:
	Fixed(void);
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	~Fixed(void);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator> (Fixed const &other) const;
	bool	operator< (Fixed const &other) const;
	bool	operator>= (Fixed const &other) const;
	bool	operator<= (Fixed const &other) const;
	bool	operator== (Fixed const &other) const;
	bool	operator!= (Fixed const &other) const;
	Fixed	operator+ (Fixed const &other) const;
	Fixed	operator- (Fixed const &other) const;
	Fixed	operator* (Fixed const &other) const;
	Fixed	operator/ (Fixed const &other) const;
	Fixed& 	operator++ (void);
	Fixed&	operator-- (void);
	Fixed	operator++ (int);
	Fixed	operator-- (int);
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif