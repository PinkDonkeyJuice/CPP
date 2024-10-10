#pragma once

#include <string>
#include <iostream>

class WrongAnimal
{
private:
	protected:
		std::string _type;

public:
    WrongAnimal();
	WrongAnimal(const WrongAnimal &ref);
    ~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &ref);
	void	makeSound() const;
	std::string	getType() const;
};
