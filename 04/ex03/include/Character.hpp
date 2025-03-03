#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
protected:
	std::string _name;
	AMateria	*_inventory[4];

public:
    Character();
	Character(std::string name);
    Character(const  Character &copy);
    ~Character();

	std::string const & getName() const;
	AMateria *getSlot(int idx) const;
	void equip(AMateria* m);
	void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
    Character &operator=(const  Character &src);
};

#endif