#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cctype>

class ScalarConverter
{
private:
	std::string	_input;
	std::string	_type;
	int			_int_val;
	double		_double_val;
	float		_float_val;
	char		_char_val;

public:
    ScalarConverter();
	ScalarConverter(const std::string input);
    ScalarConverter(const  ScalarConverter &copy);
    ~ScalarConverter();

	void	fromInt(void);
	void	fromChar(void);
	void	fromDouble(void);
	void	fromFloat(void);
	void	printOutput(void);
    ScalarConverter &operator=(const  ScalarConverter &src);
	void convert(void);
	void	printOutput() const;
	std::string getType(const std::string input);

	class ConversionErrorException : public std::exception
	{
		public:
			const char *what() const throw();
	};
};
