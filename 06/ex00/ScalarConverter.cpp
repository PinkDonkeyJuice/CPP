#include "ScalarConverter.h"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::~ScalarConverter()
{

}

std::string getType(const std::string input)
{
	int i = 0;
	bool	dec_point = false;

	if (input.length == 0)
		return ("empty");
	else if (input.length == 1 && !std::isdigit(input[0]))
		return ("char");
	else
	{
		while (std::isdigit(input[i]) || input[i] == '.' || (input[i] == 'f' && i == input.length - 1))
		{
			if (input[i] == '.')
			{
					if (dec_point == true)
					return ("unkown type");
				else
					dec_point = true;
			}
			if (input[i] == 'f')
				return ("float");
			
		}
	}

}

static void	ScalarConverter::convert(const std::string str_value)
{
	
}