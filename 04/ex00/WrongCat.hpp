#pragma once

#include <iostream>
#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:

public:
    WrongCat();
	WrongCat(const WrongCat &ref);
    ~WrongCat();

	void	makeSound() const;
	WrongCat &operator=(const WrongCat &ref);
};