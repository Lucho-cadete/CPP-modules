/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 18:06:17 by lucho             #+#    #+#             */
/*   Updated: 2026/10/16 20:37:02 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	ScalarConverter{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(ScalarConverter const &other);
		~ScalarConverter(void);
	public:
		static void	convert(std::string const &literal);
};
