/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:01 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 14:21:03 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "*Undefined animal sound*" << std::endl;
}

std::string	Animal::getType() const
{
	return(this->_type);
}

Animal &Animal::operator=(Animal const &newAnimal)
{
	this->_type = newAnimal._type;
	std::cout << "Animal assignement operator" << std::endl;
	return (*this);
}

Animal::Animal(const Animal &ref)
{
	this->_type = ref._type;
	std::cout << "Animal copy constructor called" << std::endl;
}
