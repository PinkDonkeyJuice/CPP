#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(const Animal &ref)
{
	std::cout << "Animal copy constructor called" << std::endl;
	this->_type = ref._type;
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
	this->_type = newAnimal.getType();
	return (*this);
}