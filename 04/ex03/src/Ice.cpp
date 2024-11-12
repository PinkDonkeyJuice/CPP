#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &ref) : AMateria(ref)
{
    std::cout << "Ice Copy Constructor called";
	
}

Ice &Ice::operator=(const Ice &ref)
{
	if (this != &ref)
		*this = ref;
	return *this;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
