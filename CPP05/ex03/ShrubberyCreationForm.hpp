/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 19:52:14 by lucho             #+#    #+#             */
/*   Updated: 2026/10/12 20:22:17 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class	ShrubberyCreationForm: public AForm{
	private:
		std::string _target;
		void executeAction() const;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);

		class FileImpossibleToOpenException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
