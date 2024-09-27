/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:19:47 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/08/07 11:45:45 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook phonebook;
	std::string input = "";
	
	phonebook.welcome();
	std::cin >> input;
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			phonebook.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			phonebook.printContacts();
			phonebook.search();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}