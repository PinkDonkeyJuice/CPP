#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const std::string input): _input(input)
{
	std::cout << "Scalar Converter default constructor called for " << this->_input << std::endl;
	this->_type = getType(this->_input);
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

std::string ScalarConverter::getType(const std::string input)
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
		if (input[i] == '.')
			return ("unknown type");
		while (std::isdigit(input[i]) || input[i] == '.')
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
		if (i == input.length())
			return ("unknown type");
		if (input[i] == 'f' && i == input.length() - 1)
			return ("float");
		if (has_point == true)
			return ("double");
		else
			return ("int");
	}
}

void	ScalarConverter::convert(void)
{
	std::string type;
	std::string types[4] = {"char", "int", "double", "float"};
	void	(ScalarConverter::*fnPointers[])(void) = {&ScalarConverter::fromChar, &ScalarConverter::fromInt};

	for (int i = 0; i < 4; i++)
	{
		if (this->_type == types[i])
		{
			(this->*fnPointers[i])();
			return ;
		}
	}
	throw ScalarConverter::ConversionErrorException();
	
	/* if (type == "char")
	{
		this->_int_val = std::stoi(input);
		this->_double_val = static_cast<double>(this->_int_val);
		this->_float_val = static_cast<float>(this->_int_val);
	} */
}

void	ScalarConverter::printOutput(void) const
{
	if (this->_type != "naninf")
	{
		if (std::isprint(this->_char_val))
			std::cout << "char: '" << this->_char_val << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: Impossible" << std::endl;

	if (this->_type != "naninf")
	{
		std::cout << "int: " << this->_int_val << std::endl;
	}
	else
		std::cout << "int: Impossible" << std::endl;
	if (this->_type != "naninf")
	{
		std::cout << "float: " << this->_float_val << std::endl;
	}
	else
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "float: nanf" << std::endl;
		else if (this->_input[0] == '+')
			std::cout << "float: +inff";
		else
			std::cout << "float: -inff";
	}
	if (this->_type != "naninf")
	{
		std::cout << "double: " << this->_double_val << std::endl;
	}
	else
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "double: nan" << std::endl;
		else if (this->_input[0] == '+')
			std::cout << "double: +inf";
		else
			std::cout << "double: -inf";
	}
}

void ScalarConverter::fromInt(void)
{
	this->_int_val = static_cast<int>(std::stoi(this->_input));
	this->_double_val = static_cast<double>(this->_int_val);
	this->_float_val = static_cast<float>(this->_int_val);
}

void	ScalarConverter::fromFloat(void)
{
	this->_float_val = static_cast<float>(std::stof(this->_input));
	this->_int_val = static_cast<int>(this->_float_val);
	this->_double_val = static_cast<double>(this->_double_val);
}

void	ScalarConverter::fromDouble(void)
{
	this->_double_val = static_cast<double>(std::stod(this->_input));
	this->_float_val = static_cast<float>(this->_double_val);
	this->_int_val = static_cast<int>(this->_double_val);
}

void	ScalarConverter::fromChar(void)
{
	this->_char_val = static_cast<char>(this->_input[0]);
	this->_int_val = static_cast<int>(this->_char_val);
	this->_double_val = static_cast<double>(this->_int_val);
	this->_float_val = static_cast<float>(this->_int_val);
}