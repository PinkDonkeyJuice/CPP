#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:

public:
    Ice();
    Ice(const  Ice &copy);
    ~Ice();

	AMateria* clone() const;
    Ice &operator=(const  Ice &src);
	void use(ICharacter& target);
};

#endif