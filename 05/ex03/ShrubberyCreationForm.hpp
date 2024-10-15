#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;

public:
    ShrubberyCreationForm(const std::string target);
    ShrubberyCreationForm(const  ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const  ShrubberyCreationForm &src);
	std::string getTarget() const;
	void	execute(Bureaucrat& executor) const;
};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const &rSym);