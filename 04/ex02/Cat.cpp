/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:21:39 by gyvergni          #+#    #+#             */
/*   Updated: 2024/11/08 14:21:41 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat default constructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << this->_type << " goes *meow*" << std::endl;
}

Cat &Cat::operator=(Cat const &newCat)
{
	this->_type = newCat._type;
	delete(this->_brain);
	this->_brain = new Brain();
	*this->_brain = *newCat._brain;
	std::cout << "Cat assignement operator called" << std::endl;
	return (*this);
}

Cat::Cat(const Cat &ref) : Animal()
{
	this->_type = ref.getType();
	this->_brain = new Brain();
	*this->_brain = *ref._brain;
	std::cout << "Cat copy constructor called" << std::endl;
}

void	Cat::setIdea(int i, std::string idea)
{
	this->_brain->brain_setIdea(i, idea);
}

void	Cat::getIdeas()
{
	int i = 0;
	while (this->_brain->getIdea(i).length() > 0)
	{
		std::cout << this->_brain->getIdea(i) << std::endl;
		i++;
	}
}