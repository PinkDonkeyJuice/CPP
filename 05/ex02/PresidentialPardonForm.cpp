#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm::AForm("Presidential pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) : AForm::AForm(ref), _target(ref._target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this == &ref)
		return (*this);
	else
		return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw(AForm::FormNotSignedException());
	else
	{
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}
