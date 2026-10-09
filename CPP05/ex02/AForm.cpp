/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucho <lucho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:45:14 by lucho             #+#    #+#             */
/*   Updated: 2026/10/09 17:01:39 by lucho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("default"), _gradeToSign(150), _gradeToExecute(150), _signed(false)
{}

AForm::AForm(AForm const &other)
	: _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _signed(other._signed)
{}

AForm& AForm::operator=(AForm const &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return(*this);
}

AForm::~AForm(void)
{}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

void AForm::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}

std::ostream &operator<<(std::ostream &out, AForm const &f)
{
	out << "AForm " << f.getName()
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to execute: " << f.getGradeToExecute()
		<< ", signed: " << (f.getSigned() ? "Yes" : "No") << ".";
	return (out);
}
