/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 17:39:25 by lucho             #+#    #+#             */
/*   Updated: 2026/09/15 21:05:42 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class	Fixed {
private:
	int _value;
	static const int _fractionalBits;

public:
	Fixed(void);
	Fixed(Fixed const &other);
	Fixed &operator=(Fixed const &other);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif