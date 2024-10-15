#include "Intern.hpp"


Intern::Intern()
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &ref)
{
     std::cout << "Intern Copy Constructor called";
	 *this = ref;
}

Intern &Intern::operator=(const Intern &ref)
{
	(void) ref;
	return *this;
}

AForm *Intern::makeForm(const std::string form, const std::string target)
{
	int i = 0;

	std::string types[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
	while (i < 3)
	{
		if (form == types[i])
		{
			std::cout << "Intern creates " << form << " form" << std::endl;
			for (int j = i + 1; j < 3; j++)
			{
				delete (forms[j]);
			}
			return (forms[i]);
		}
		delete (forms[i]);
		i++;
	}
	std::cout << "Intern can't create " << form << " form" << std::endl;
	return (NULL);
}
