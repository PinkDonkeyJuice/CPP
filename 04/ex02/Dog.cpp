/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:07:39 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/09/25 19:07:53 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Dog default destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << this->_type << " goes *woof woof*" << std::endl;
}

Dog &Dog::operator=(Dog const &newDog)
{
	this->_type = newDog.getType();
	this->_brain = new Brain();
	*this->_brain = *newDog._brain;
	return (*this);
}

Dog::Dog(const Dog &ref) : Animal()
{
	this->_type = ref.getType();
	std::cout << "Dog copy constructor called";
}
