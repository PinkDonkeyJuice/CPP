/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 11:27:49 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/15 15:59:12 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"


PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to your PhoneBook!\nEnter a prompt" << std::endl;
	std::cout << std::endl;
	std::cout << "ADD: To add a new contact." <<std::endl;
	std::cout << "SEARCH: To search for an existing contact's info." << std::endl;
	std::cout << "EXIT: To exit the PhoneBook." << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(void)
{
	static int i = 0;

	if (i > 7)
	{
		i = 0;
	}
	this->_contacts[i].init();
	this->_contacts[i].setIndex(i);
	i++;
}

void	PhoneBook::printContacts(void)
{
	std::cout << "---------- Contact list ----------" << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		this->_contacts[i].disp_contact();
	}
	std::cout << std::endl;
}

void	PhoneBook::search(void)
{
	int		index = 1;
	bool	valid = false;
	std::string	input;

	while (!valid && !std::cin.eof())
	{
		if (this->_contacts[0].getIndex() == -1)
		{
			std::cout << "No contacts have been added yet" << std::endl;
			return ;	
		}
		this->printContacts();
		std::cout << "Enter the index of the contact you are looking for: \n" << std::flush;
		std::cin >> input;
		index = std::atoi(input.c_str());
		if (index > 0 && index <= 8)
		{
			this->_contacts[index - 1].disp_info();
			valid = true;
		}
		else
		{
			std::cout << "Invalid index." << std::endl;
		}
	}
	return ;
}
