/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:20:32 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:33 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog::Dog(const Dog &ref)
{
	this->_type = ref._type;
	std::cout << "Dog Copy constructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << " goes *woof woof*" << std::endl;
}

Dog &Dog::operator=(Dog const &newDog)
{
	this->_type = newDog.getType();
	return (*this);
}