/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:19:47 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 15:27:41 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook phonebook;
	std::string input = "";
	
	phonebook.welcome();
	std::cout << "> ";
	std::getline(std::cin, input);
	while (input.compare("EXIT"))
	{
		if (std::cin.eof())
			return (0);
		if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search();
		std::cin.clear();
		std::cout << "> ";
		std::getline(std::cin, input);
	}
	return (0);
}