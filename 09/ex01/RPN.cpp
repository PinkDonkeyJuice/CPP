#include "RPN.hpp"

RPN::RPN() : _stack(), _expr()
{
};

RPN::RPN(std::string input) : _expr(input), _stack()
{
}

RPN::RPN(const RPN &ref)
{
	*this = ref;
}

RPN::~RPN()
{
}

RPN	&RPN::operator=(const RPN &ref)
{
	this->_stack = ref._stack;
	this->_expr = ref._expr;
}

void	RPN::parse_input(std::string input)
{
	std::string buffer;
	int			value;

	std::istringstream ss(input);
	std::getline(ss, buffer, ' ');
	if (!(value = atoi(buffer.c_str())))
	{
		throw(std::exception());
	}
	this->_stack.push(value);
	while (std::getline(ss, buffer, ' '))
	{
		
	}
}
