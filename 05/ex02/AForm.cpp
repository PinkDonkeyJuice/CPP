#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "AForm constructor called for " << this->getName() << " with sign grade of " << this->getSignGrade() << " and exec grade of " << this->getExecGrade() << std::endl;
	if (sign_grade > 150 || exec_grade > 150)
		throw(AForm::GradeTooLowException());
	else if (sign_grade < 1 || exec_grade < 1)
		throw(AForm::GradeTooHighException());
}

AForm::~AForm()
{
	std::cout << "Default AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &ref) : _name(ref.getName() + "_copy"), _is_signed(false), _sign_grade(ref.getSignGrade()), _exec_grade(ref.getExecGrade())
{
	std::cout << "AForm Copy Constructor called for " << this->getName() << " from " << ref.getName() << std::endl;
}

AForm &AForm::operator=(const AForm &ref)
{
	std::cout << "AForm Assignation operator called" << std::endl;
	if (this != &ref)
		this->_is_signed = ref.getSigned();
	return (*this);
}

//Methods

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getSignGrade())
		throw(AForm::GradeTooLowException());
	else if (this->getSigned() == true)
		std::cout << bureaucrat.getName() << " couldn't sign AForm " << this->getName() << " because it is already signed" << std::endl;
	else
	{
		this->_is_signed = true;
		std::cout << this->getName() << " was signed by " << bureaucrat.getName() << std::endl;
	}
}

//Getters

const std::string AForm::getName() const
{
	return (this->_name);
}

int	AForm::getSignGrade() const
{
	return(this->_sign_grade);
}

int	AForm::getExecGrade() const
{
	return(this->_exec_grade);
}

bool	AForm::getSigned() const
{
	return(this->_is_signed);
}

//Exceptions

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low for this AForm");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high for this AForm");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("This form hasn't been signed yet");
}
