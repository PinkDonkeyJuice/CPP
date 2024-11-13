#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &ref) : AMateria(ref)
{
    std::cout << "Cure Copy Constructor called";
}

Cure &Cure::operator=(const Cure &ref)
{
	this->_type = ref._type;
	if (this != &ref)
		*this = ref;
	return *this;
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
