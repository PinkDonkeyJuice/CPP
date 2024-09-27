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

void	Dog::makeSound() const
{
	std::cout << this->_type << " goes *woof woof*" << std::endl;
}

Dog &Dog::operator=(Dog const &newDog)
{
	this->_type = newDog.getType();
	return (*this);
}