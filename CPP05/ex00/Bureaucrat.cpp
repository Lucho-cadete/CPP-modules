
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: _name(name)//here added because _name is const!
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade >150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	:_name(other._name) 
{
	this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return(*this);
}

Bureaucrat::~Bureaucrat(void)
{
}

std::string Bureaucrat::getName() const
{
	return(this->_name);
}

int Bureaucrat::getGrade () const
{
	return(this->_grade);
}

void incrementGrade (std::string name, int grade)
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void decrementGrade (std::string name, int grade);
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char*Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade too high");
}

const char*Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade too low");
}
