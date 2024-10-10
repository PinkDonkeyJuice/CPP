#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_type = "Cat";
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
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