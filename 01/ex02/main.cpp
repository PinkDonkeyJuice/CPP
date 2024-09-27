/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 11:30:46 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/11 16:02:23 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*pointer = &str;
	std::string	&ref = str;

	std::cout << &str << ": Memory address of str" << std::endl;
	std::cout << &pointer << ": Memory address of pointer to str" << std::endl;
	std::cout << &ref << ": Memory address of pointer to ref" << std::endl;

	std::cout << str << ": value of str" << std::endl;
	std::cout << *pointer << ": value pointed to by pointer" << std::endl;
	std::cout << ref << ": value pointed to by ref" << std::endl;
}
