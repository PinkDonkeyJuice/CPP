/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 00:36:32 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat *Steve = new Bureaucrat("Steve", 1);

	AForm *pres = new PresidentialPardonForm("Eric");
	AForm *shrub = new ShrubberyCreationForm("Home");
	AForm *robot = new RobotomyRequestForm("Michael");

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
}