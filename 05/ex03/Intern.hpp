#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
private:

public:
    Intern();
    Intern(const  Intern &copy);
    ~Intern();

    Intern &operator=(const  Intern &src);
	AForm *makeForm(const std::string form, const std::string target);
};
