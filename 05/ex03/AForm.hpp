/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:56:28 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/30 19:25:27 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
    AForm();
	AForm(const std::string name, const int sign_grade, const int exec_grade);
    AForm(const  AForm &src);
    virtual ~AForm();

	//Exceptions

	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	//Overloaders
    AForm &operator=(const  AForm &src);

	//Methods
	void	beSigned(Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat &executor) const = 0;

	//Getters
	const std::string getName() const;
	bool			getSigned() const;
	int		getSignGrade() const;
	int		getExecGrade() const;

};

std::ostream &operator<<(std::ostream &o, AForm *a);