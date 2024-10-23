#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &ref)
{
	(void)ref;
    std::cout << "Serializer Copy Constructor called";
}

Serializer &Serializer::operator=(const Serializer &ref)
{
	(void)ref;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}
