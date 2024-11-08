#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &ref)
{
     std::cout << "Ice Copy Constructor called";
}

Ice &Ice::operator=(const Ice &ref)
{

}

AMateria* clone()
{
	return (new Ice());
}

void	use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
