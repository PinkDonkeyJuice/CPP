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
    std::cout << "Character constructor called for " << name << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
	}
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &ref)
{
	*this = ref;
}

Character &Character::operator=(const Character &ref)
{
	if (this != &ref)
	{	
		this->_name = ref._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
			if (ref._inventory[i] != NULL)
				this->_inventory[i] = ref._inventory[i]->clone();
		}
	}
	return *this;
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	if (!m)
		return ;
	for (i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << " equipped a materia of type " << m->getType() << " in slot " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << this->_name << " cannot equip " << m->getType() << " because inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 1 && idx < 5 && this->_inventory[idx - 1])
	{
		std::cout << this->_name << " unequips " << this->_inventory[idx - 1]->getType() << " from slot " << idx << std::endl;
		this->_inventory[idx - 1] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 1 && idx < 5 && this->_inventory[idx - 1])
		this->_inventory[idx - 1]->use(target);
	else
		std::cout << this->_name << " has no materia to use in slot " << idx << std::endl;
}

AMateria	*Character::getSlot(int idx) const
{
	if (idx >= 1 && idx < 5)
		return (this->_inventory[idx - 1]);
	return NULL;
}