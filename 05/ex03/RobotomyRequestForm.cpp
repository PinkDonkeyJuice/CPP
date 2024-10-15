#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm::AForm("Robotomy", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref) : AForm::AForm(ref), _target(ref._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	(void) ref;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

static int success = 0;

void RobotomyRequestForm::execute(Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw(AForm::FormNotSignedException());
	else if (success++ % 2)
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::cout << "*DRILLING NOISES*" << std::endl <<
		this->_target << " has been robotomized" << std::endl;
	}
	else
		std::cout << "Robotomy failed" << std::endl;
}
