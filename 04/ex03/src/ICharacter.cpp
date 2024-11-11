#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor called" << std::endl;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter destructor called" << std::endl;
}

ICharacter::ICharacter(const ICharacter &ref)
{
     std::cout << "ICharacter Copy Constructor called";
}

ICharacter &ICharacter::operator=(const ICharacter &ref)
{

}
