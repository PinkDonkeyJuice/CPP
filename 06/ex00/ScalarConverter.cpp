#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input): _input(input)
{
	std::cout << "Scalar Converter default constructor called for " << this->_input << std::endl;
	this->_type = findType(this->_input);
	try
	{
		this->convert();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
	this->printOutput();
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
	(void)ref;
    std::cout << "ScalarConverter Copy Constructor called";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{
	(void)ref;
	return (*this);
}

std::string findType(const std::string input)
{
	size_t i = 0;
	bool	has_point = false;

	if (input.length() == 0)
		return ("empty");
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return ("char");
	if (input == "-inff" || input == "inff" || input == "inf" || input == "-inf" || input == "nan" || input == "nanf")
		return ("naninf");
	else
	{
		if (input[0] == '-' || input[0] == '+')
			i++;
		if (input[i] == '.' || input[i] == 'f')
			return ("unknown type");
		while (std::isdigit(input[i]) || input[i] == '.' || input[i] == 'f')
		{
			if (input[i] == '.')
			{
					if (has_point == true)
					return ("unknown type");
				else
					has_point = true;
			}
			i++;
		}
		if (i != input.length())
			return ("unknown type");
		if (input[i - 1] == 'f')
			return ("float");
		if (has_point == true)
			return ("double");
		else
			return ("int");
	}
}

void	ScalarConverter::convert(void)
{
	std::string types[4] = {"char", "int", "double", "float"};
	void	(ScalarConverter::*fnPointers[])(void) = {&ScalarConverter::fromChar, &ScalarConverter::fromInt, &ScalarConverter::fromDouble, &ScalarConverter::fromFloat};

	for (int i = 0; i < 4; i++)
	{
		if (this->_type == types[i])
		{
			(this->*fnPointers[i])();
			return ;
		}
	}
	if (this->_type == "naninf")
		return ;
	throw ScalarConverter::ConversionErrorException();
	
	/* if (type == "char")
	{
		this->_int_val = std::stoi(input);
		this->_double_val = static_cast<double>(this->_int_val);
		this->_float_val = static_cast<float>(this->_int_val);
	} */
}

void	printOutput(void)
{
	//char
	if (this->_type != "naninf")
	{
		if (std::isprint(this->_char_val))
			std::cout << "char: '" << this->_char_val << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;

	//int
	if (this->_type != "naninf")
	{
		std::cout << "int: " << this->_int_val << std::endl;
	}
	else
		std::cout << "int: Impossible" << std::endl;
	
	//float
	if (this->_type != "naninf")
	{
		std::cout << "float: " << this->_float_val;
		if (this->_input.find('.') == std::string::npos || this->_input.find(".0f") != std::string::npos || this->_input.find(".0") == this->_input.length() - 2)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "float: nanf" << std::endl;
		else if (this->_input[0] == '-')
			std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: +inff" << std::endl;
	}

	//double
	if (this->_type != "naninf")
	{
		std::cout << "double: " << this->_double_val;
		if (this->_input.find('.') == std::string::npos || this->_input.find(".0f") != std::string::npos || this->_input.find(".0") == this->_input.length() - 2)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "double: nan" << std::endl;
		else if (this->_input[0] == '-')
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: +inf" << std::endl;
	}
}

void ScalarConverter::fromInt(void)
{
	char *pend;
	long int long_val;
	
	long_val = std::strtol(this->_input.c_str(), &pend, 10);
	if (*pend != '\0' || long_val < -2147483648 || long_val > 2147483647)
	{
		std::cout << "Int value out of range" << std::endl;
		throw(ScalarConverter::ConversionErrorException());
		return ;
	}
	fromDouble();
}

void	ScalarConverter::fromFloat(void)
{
	char *pend;

	this->_input = this->_input.substr(0, std::strlen(this->_input.c_str()) - 1);
	this->_double_val = static_cast<double>(std::strtod(this->_input.c_str(), &pend));
	if (*pend != '\0')
	{
		std::cout << "Float value out of range" << std::endl;
		throw(ScalarConverter::ConversionErrorException());
		return ;
	}
	this->_float_val = static_cast<float>(this->_double_val);
	if (this->_double_val >= 2147483648.0 || this->_double_val <= -2147483649.0)
	{
		throw(ScalarConverter::ConversionErrorException());
	}
	else
		this->_int_val = static_cast<int>(this->_double_val);
	this->_char_val = static_cast<double>(this->_double_val);
}

void	ScalarConverter::fromDouble(void)
{
	char *pend;

	this->_double_val = static_cast<double>(std::strtod(this->_input.c_str(), &pend));
	if (*pend != '\0')
	{
		std::cout << "Float value out of range" << std::endl;
		throw(ScalarConverter::ConversionErrorException());
		return ;
	}
	this->_float_val = static_cast<float>(this->_double_val);
	if (this->_double_val >= 2147483648.0 || this->_double_val <= -2147483649.0)
	{
		throw(ScalarConverter::ConversionErrorException());
	}
	else
		this->_int_val = static_cast<int>(this->_double_val);
	this->_char_val = static_cast<double>(this->_double_val);
}

void	ScalarConverter::fromChar(void)
{
	this->_char_val = static_cast<char>(this->_input[0]);
	this->_int_val = static_cast<int>(this->_char_val);
	this->_double_val = static_cast<double>(this->_int_val);
	this->_float_val = static_cast<float>(this->_int_val);
}

const char* ScalarConverter::ConversionErrorException::what() const throw() {
    return "Conversion Error";
}

std::string	ScalarConverter::getType()
{
	return (this->_type);
}
