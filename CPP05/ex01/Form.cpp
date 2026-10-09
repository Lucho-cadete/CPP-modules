/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:45:14 by lucho             #+#    #+#             */
/*   Updated: 2026/10/09 16:46:39 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{}

Form::Form(Form const &other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _signed(other._signed)
{}

Form& Form::operator=(Form const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return(*this);
}

Form::~Form(void)
{}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

void Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form const &f)
{
	out << "Form " << f.getName()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", signed: " << (f.getSigned() ? "Yes" : "No") << ".";
	return (out);
}
