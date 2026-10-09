
#pragma once

#include <string>
#include <exception>
#include <iostream>

class	Bureaucrat{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		Bureaucrat& operator=(Bureaucrat const &other);
		~Bureaucrat(void);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade (void);
		void decrementGrade (void);

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
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);
