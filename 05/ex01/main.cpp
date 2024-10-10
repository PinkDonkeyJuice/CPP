/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:05:16 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/30 19:36:20 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Bureaucrat *a = new Bureaucrat("Harry", 150);
		Bureaucrat *b = new Bureaucrat("John", 1);
		Form *big_contract = new Form("Contract for big biznis", 1, 1);
		Form *small_contract = new Form("Contract for smol biznis", 150, 150);
		std::cout << std::endl;

		std::cout << "\033[34mTesting\033[0m" << std::endl;
		std::cout << a;

		a->decrementGrade();
		std::cout << a;

		a->signForm(*big_contract);
		a->signForm(*small_contract);
		b->signForm(*big_contract);
		b->incrementGrade();
		std::cout << b;
		b->decrementGrade();
		std::cout << b;
		b->incrementGrade();
		std::cout << b;

		delete a;
		delete b;
		delete big_contract;
		delete small_contract;
		
		std::cout << std::endl;
	}
}