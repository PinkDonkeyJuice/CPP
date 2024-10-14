#include "Bureaucrat.hpp"
#include "AForm.hpp"

//Constructors

Bureaucrat::Bureaucrat(): _name("default")
{
	std::cout << "default constructor called for default Bureaucrat";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade " << grade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Can't initalise " <<this->getName() << ": grade too high!" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Can't initalise " <<this->getName() << ": grade too low!" << std::endl;
	}
}
Bureaucrat::Bureaucrat(const Bureaucrat &ref): _name(ref.getName() + "_copy")
{
	std::cout << "Bureaucrat copy constructor called from " << ref.getName() << std::endl;
	this->setGrade(ref.getGrade());
}

//Destructor

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << this->getName() << std::endl;
}

//Overload

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Bureaucrat Assignation operator called from " << src.getName() << std::endl;
	this->setGrade(src.getGrade());
	return (*this);
}

//Member functions

void	Bureaucrat::incrementGrade()
{
	try
	{
		this->setGrade(this->getGrade() - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "Incrementation of " << this->getName() << "'s grade failed : " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade()
{
	try
	{
		this->setGrade(this->getGrade() + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "Decrementation of " << this->getName() << "'s grade failed : " << e.what() << std::endl;
	}
}

const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int		Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade = grade;
}

void	Bureaucrat::signForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign form because : " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm &AForm)
{
	try
	{
		AForm.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

//Exceptions

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &o, Bureaucrat *a)
{
	o << "Bureaucrat " << a->getName() << " has a grade of " << a->getGrade() << std::endl;
	return (o);
}
