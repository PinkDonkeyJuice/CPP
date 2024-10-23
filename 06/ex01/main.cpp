#include "Serializer.hpp"

#include <iostream>

void    printData(Data data)
{
    std::cout << "i: " << data.i << std::endl;
    std::cout << "s: " << data.s << std::endl;
}

int main()
{
    Data data;

    data.i = 42;
    data.s = "More classes please";

    printData(data);
    uintptr_t raw = Serializer::serialize(&data);
    Data *r_data = Serializer::deserialize(raw);
    printData(*r_data);
}