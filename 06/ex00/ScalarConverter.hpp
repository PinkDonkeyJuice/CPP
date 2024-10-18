#pragma once

#include <string>
#include <iostream>
#include <cstdlib>

class ScalarConverter
{
private:

public:
    ScalarConverter();
    ScalarConverter(const  ScalarConverter &copy);
    ~ScalarConverter();

    ScalarConverter &operator=(const  ScalarConverter &src);
	void *convert(const std::string input);

};