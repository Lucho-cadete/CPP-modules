/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:45:24 by lucho             #+#    #+#             */
/*   Updated: 2026/10/09 23:25:15 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class	AForm{
	private:
		std::string const	_name;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		bool				_signed;

	public:
		AForm(void);
		AForm(AForm const &other);
		AForm &operator=(AForm const &other);
		virtual ~AForm(void);
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getSigned() const;

		void beSigned(Bureaucrat const &b);
		void execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
	protected:
		virtual void executeAction() const = 0;
};
std::ostream &operator<<(std::ostream &out, AForm const &);
