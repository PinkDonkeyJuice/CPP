#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Default form constructor called" << std::endl;
}

Form::Form(const std::string name, const int sign_grade, const int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form constructor called for " << this->getName() << " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << std::endl;
	if (sign_grade > 150 || exec_grade > 150)
		throw(Form::GradeTooLowException());
	else if (sign_grade < 1 || exec_grade < 1)
		throw(Form::GradeTooHighException());
}

Form::~Form()
{
	std::cout << "Default form destructor called" << std::endl;
}

Form::Form(const Form &ref) : _name(ref.getName() + "_copy"), _is_signed(false), _sign_grade(ref.getSignGrade()), _exec_grade(ref.getExecGrade())
{
	std::cout << "Form Copy Constructor called for " << this->getName() << " from " << ref.getName() << std::endl;
}

Form &Form::operator=(const Form &ref)
{
	std::cout << "Form Assignation operator called" << std::endl;
	if (this != &ref)
		this->_is_signed = ref.getSigned();
	return (*this);
}

//Methods

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else if (this->getSigned() == true)
		std::cout << bureaucrat.getName() << " couldn't sign form " << this->getName() << " because it is already signed" << std::endl;
	else
	{
		this->_is_signed = true;
		std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
	}
}

//Getters

const std::string Form::getName() const
{
	return (this->_name);
}

int	Form::getSignGrade() const
{
	return(this->_sign_grade);
}

int	Form::getExecGrade() const
{
	return(this->_exec_grade);
}

bool	Form::getSigned() const
{
	return(this->_is_signed);
}

//Exceptions

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this form");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this form");
}
