#pragma once

#include <string>
#include <iostream>

#include "AForm.hpp"

class AForm;

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
	void	signForm(AForm &AForm);
	void	executeForm(AForm &AForm);

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