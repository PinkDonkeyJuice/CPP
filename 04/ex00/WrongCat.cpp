#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &ref)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "*Weird meow*" << std::endl;
}
