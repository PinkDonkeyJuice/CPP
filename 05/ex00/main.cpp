/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/30 11:14:50 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Harry", 150);
		Bureaucrat *b = new Bureaucrat("John", 1);
		Bureaucrat *c = new Bureaucrat("Kevin", 0);

		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;

		a->decrementGrade();
		std::cout << a;

		b->incrementGrade();
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		b->incrementGrade();
		std::cout << b;

		delete a;
		delete b;
		delete c;
		std::cout << std::endl;
	}
}