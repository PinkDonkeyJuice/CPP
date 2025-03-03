#pragma once

#include <string>
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string _name;
	int			_grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
	Bureaucrat(const  Bureaucrat &copy);
    ~Bureaucrat();

	const std::string getName() const;
	int			getGrade() const;
    void		setGrade(int grade);
	
	Bureaucrat &operator=(const  Bureaucrat &src);

	void	incrementGrade();
	void	decrementGrade();

	//Methods
	void	signForm(Form &form);

	//Exceptions
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);