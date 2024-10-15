/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 02:13:17 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Bureaucrat	*Steve = new Bureaucrat("Steve", 1);
	Intern		*Jack = new Intern();
	AForm 		*pres;
	AForm		*shrub;
	AForm		*robot;

	pres = Jack->makeForm("presidential pardon", "Mike");
	shrub = Jack->makeForm("shrubbery creation", "Home");
	robot = Jack->makeForm("robotomy request", "Fiona");
	
	try 
	{
		(*pres).beSigned(*Steve);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to sign the Form : " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Steve->executeForm(*pres);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to execute the Form " << Steve->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		(*shrub).beSigned(*Steve);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to sign the Form : " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Steve->executeForm(*shrub);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to execute the Form " << Steve->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		(*robot).beSigned(*Steve);
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to sign the Form : " << e.what() << "\033[0m" << std::endl;
	}
	try
	{
		Steve->executeForm(*robot);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to execute the Form " << Steve->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Steve->executeForm(*robot);
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[33m" << Steve->getName() << " was not able to execute the Form " << Steve->getName() << ": " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << std::endl;
	delete Steve;
	delete Jack;
}