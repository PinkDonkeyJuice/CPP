#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	Bureaucrat& _target;

public:
    ShrubberyCreationForm(Bureaucrat& target);
    ShrubberyCreationForm(const  ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const  ShrubberyCreationForm &src);
	void	execute(Bureaucrat& executor) const;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &rSym);