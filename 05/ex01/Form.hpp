/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
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

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_is_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
    Form();
	Form(const std::string name, const int sign_grade, const int exec_grade);
    Form(const  Form &src);
    ~Form();

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

	//Overloaders
    Form &operator=(const  Form &src);

	//Methods
	void	beSigned(Bureaucrat &bureaucrat);

	//Getters
	const std::string getName() const;
	bool			getSigned() const;
	int		getSignGrade() const;
	int		getExecGrade() const;

};

std::ostream &operator<<(std::ostream &o, Form *a);