#include "Character.hpp"

Character::Character()
{
    std::cout << "Character default constructor called" << std::endl;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &ref)
{
     std::cout << "Character Copy Constructor called";
}

Character &Character::operator=(const Character &ref)
{

}