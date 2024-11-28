/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/27 14:55:13 by gyvergni         ###   ########.fr       */
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

	Bureaucrat *Rick = new Bureaucrat(*Steve);
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
	delete Rick;
	delete pres;
	delete shrub;
	delete robot;
}
