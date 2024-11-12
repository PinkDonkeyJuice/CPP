#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
private:

public:
    Cure();
    Cure(const  Cure &copy);
    ~Cure();

	virtual AMateria* clone() const;
    Cure &operator=(const  Cure &src);
	virtual void use(ICharacter& target);
};

#endif