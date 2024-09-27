/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:17 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/10 12:17:01 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const 
{
	std::string input = "";
	bool		valid = false;

	do
	{
		std::cout << str << std::flush;
		std::cin >> input;
		if (std::cin.good() && !input.empty())
			valid = true;
		else
		{
			std::cout << "Invalid input" << std::endl;
		}
	} while (!valid);
	return (input);
}

void	Contact::init(void)
{
	this->_firstName = this->_getInput("Enter your first name: ");
	this->_lastName = this->_getInput("Enter your last name: ");	
	this->_nickName = this->_getInput("Enter your nickname: ");
	this->_phoneNumber = this->_getInput("Enter your phone number: ");
	this->_darkestSecret = this->_getInput("Enter your darkest secret: ");
	std::cout << std::endl;
}

void	Contact::setIndex(int i)
{
	this->index = i + 1;
}

void	Contact::disp_contact(void)
{
	if (this->_firstName.empty() | this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << this->_firstName;
	std::cout << "|" << std::setw(10) << this->_lastName;
	std::cout << "|" << std::setw(10) << this->_nickName;
	std::cout << "|" << std::endl;
}

void	Contact::disp_info(void)
{
	if (this->_firstName.empty() | this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "---- CONTACT #" << index << " ----" << std::endl;
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}