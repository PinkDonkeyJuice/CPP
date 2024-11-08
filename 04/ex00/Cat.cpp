/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:20:21 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 14:20:25 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &ref)
{
	this->_type = ref._type;
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << " goes *meow*" << std::endl;
}

Cat &Cat::operator=(Cat const &newCat)
{
	this->_type = newCat.getType();
	return (*this);
}