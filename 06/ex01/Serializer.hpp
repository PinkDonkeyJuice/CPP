#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

#include "Data.h"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer(const std::string input);
    Serializer(const  Serializer &copy);

public:
    ~Serializer();

	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
    Serializer &operator=(const  Serializer &src);
};
