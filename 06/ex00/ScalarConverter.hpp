#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

class ScalarConverter
{
private:
    ScalarConverter();
	ScalarConverter(const std::string input);
    ScalarConverter(const  ScalarConverter &copy);
    ~ScalarConverter();
    ScalarConverter &operator=(const  ScalarConverter &src);

public:
	void convert(void);
	std::string findType(const std::string input);
	std::string		getType();
	class ConversionErrorException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
