/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:12:17 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/10/18 11:14:45 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"

Contact::Contact() : index(-1)
{
}

Contact::~Contact()
{
}

std::string Contact::_getInput(std::string str) const 
{
	std::string input = "hell";
	bool		valid = false;

	while (!valid && !std::cin.eof())
	{
		std::cout << str << std::endl;
		std::cin.clear();
		std::getline(std::cin, input);
		if (!input.empty())
		{
			valid = true;
		}
		else
		{
			std::cout << "Invalid input" << std::endl;
		}
	}
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

std::string cutString(std::string str)
{
	if (str.length() <= 10)
		return (str);
	else
		return (str.replace(9, str.length(), "."));
}

void	Contact::disp_contact(void)
{
	if (this->_firstName.empty() | this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << "|" << std::setw(10) << this->index;
	std::cout << "|" << std::setw(10) << cutString(this->_firstName);
	std::cout << "|" << std::setw(10) << cutString(this->_lastName);
	std::cout << "|" << std::setw(10) << cutString(this->_nickName);
	std::cout << "|" << std::endl;
}

void	Contact::disp_info(void)
{
	if (this->_firstName.empty() | this->_lastName.empty() || this->_nickName.empty())
		return ;
	std::cout << std::endl;
	std::cout << "---- CONTACT #" << index << " ----" << std::endl;
	std::cout << "First Name: " <<  this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
	std::cout << std::endl;
}

int	Contact::getIndex()
{
	return (this->index);
}