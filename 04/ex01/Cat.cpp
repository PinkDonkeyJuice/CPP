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
	this->_brain = new Brain();
	*this->_brain = *newCat._brain;
	return (*this);
}

Cat::Cat(const Cat &ref) : Animal()
{
	this->_type = ref.getType();
	std::cout << "Cat copy constructor called";
}