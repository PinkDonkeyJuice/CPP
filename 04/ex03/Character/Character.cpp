#include "Character.hpp"

Character::Character()
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_name = "Default";
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	this->_name = name;
    std::cout << "Character default constructor called" << std::endl;
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &ref) : _name(ref._name)
{
    std::cout << "Character Copy Constructor called";
	for (int i = 0; i < 4; i++)
	{
		if (ref._inventory[i] == NULL)
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = 
	}
}

Character &Character::operator=(const Character &ref)
{

}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	while (this->_inventory[i] != NULL && i < 4)
		i++;
	if (i != 4)
		this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	this->_inventory[idx]->use(target);
}