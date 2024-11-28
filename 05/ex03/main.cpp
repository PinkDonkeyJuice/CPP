/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/27 14:56:35 by gyvergni         ###   ########.fr       */
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
	
	Steve->signForm(*pres);
	std::cout << std::endl;
	Steve->executeForm(*pres);
	Steve->signForm(*shrub);
	*shrub = *robot;
	Steve->executeForm(*shrub);
	Steve->signForm(*shrub);
	Steve->executeForm(*shrub);
	Steve->signForm(*robot);
	Steve->executeForm(*robot);
	delete Steve;
	delete pres;
	delete shrub;
	delete robot;
	delete Jack;
}