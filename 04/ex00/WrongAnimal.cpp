/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:10:06 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/27 10:57:42 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	this->_type = ref._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	this->_type = ref._type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Undefined WrongAnimal sound*" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return(this->_type);
}