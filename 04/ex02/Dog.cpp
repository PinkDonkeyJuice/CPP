/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:07:39 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/11/13 10:40:10 by gyvergni         ###   ########.fr       */
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
	delete this->_brain;
	this->_type = newDog.getType();
	this->_brain = new Brain();
	*this->_brain = *newDog._brain;
	std::cout << "Dog assignement operator called" << std::endl;
	return (*this);
}

Dog::Dog(const Dog &ref) : Animal()
{
	if (this != &ref)
		*this = ref;
	std::cout << "Dog copy constructor called" << std::endl;
}

void	Dog::setIdea(int i, std::string idea)
{
	this->_brain->brain_setIdea(i, idea);
}

void	Dog::getIdeas()
{
	int i = 0;
	while (this->_brain->getIdea(i).length() > 0)
	{
		std::cout << this->_brain->getIdea(i) << std::endl;
		i++;
	}
}
