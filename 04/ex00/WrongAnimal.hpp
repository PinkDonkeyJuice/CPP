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
    ~WrongAnimal();

	void	makeSound() const;
	std::string	getType() const;

};