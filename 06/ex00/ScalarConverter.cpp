#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &ref)
{
     std::cout << "ScalarConverter Copy Constructor called";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &ref)
{

}

std::string getType(const std::string input)
{
	int i = 0;
	bool	has_point = false;

	if (input.length() == 0)
		return ("empty");
	else if (input.length() == 1 && !std::isdigit(input[0]))
		return ("char");
	if (input == "-inff" || input == "inff")
		return ("float");
	if (input == "-inf" || input == "inf" || input == "nan")
		return ("double");
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

void	*ScalarConverter::convert(const std::string input)
{
	std::string type;

	type = getType(input);
	if (type == "int")
		return(stoi(input));
}
