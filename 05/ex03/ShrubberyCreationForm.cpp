#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm::AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm::AForm(ref), _target(ref._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	(void) ref;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(AForm::GradeTooLowException());
	else if (!this->getSigned())
		throw(AForm::FormNotSignedException());
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());
		for (int i = 0; i < 3; i++)
		{
			outfile <<
			"       _-_" << std::endl <<
			"    /~~   ~~\\ " << std::endl <<
			" /~~         ~~\\ " << std::endl <<
			" {               } " << std::endl <<
 			" \\  _-     -_  // " << std::endl <<
			"   ~  \\ //  ~     " << std::endl <<
			"_- -   | | _- _    " << std::endl <<
			"  _ -  | |   -_    " << std::endl <<
			"      // \\        " << std::endl <<
			std::endl;
		}
		outfile.close();
	}
}
