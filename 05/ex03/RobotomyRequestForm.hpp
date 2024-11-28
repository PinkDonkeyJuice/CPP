#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;

public:
    RobotomyRequestForm(const std::string target);
    RobotomyRequestForm(const  RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const  RobotomyRequestForm &src);
	std::string getTarget() const;
	void	execute(Bureaucrat& executor) const;
};

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &rSym);
