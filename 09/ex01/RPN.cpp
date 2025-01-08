#include "RPN.hpp"

RPN::RPN()
{
};

RPN::RPN(std::string input) : _expr(input)
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
	return *this;
}

void	RPN::do_op(std::string buffer)
{
	int	val1;
	int val2;
	int result;

	if (buffer.length() != 1)
		throw(std::exception());
	val1 = this->_stack.top();
	this->_stack.pop();
	val2 = this->_stack.top();
	if (buffer[0] == '+')
		result = val1 + val2;
	if (buffer[0] == '-')
		result = val2 - val1;
	if (buffer[0] == '*')
		result = val2 * val1;
	if (buffer[0] == '/' )
		result = val2 / val1;
	this->_stack.push(result);
}		

void	RPN::calculate()
{
	std::string input = this->_expr;
	std::string buffer;
	int			value;

	std::istringstream ss(input);
	std::getline(ss, buffer, ' ');
	if (!(value = std::atoi(buffer.c_str())))
	{
		throw(std::exception());
	}
	this->_stack.push(value);
	while (std::getline(ss, buffer, ' '))
	{
		if (!(value = std::atoi(buffer.c_str())))
		{
			throw(std::exception());
		}
		this->_stack.push(value);
		if (std::getline(ss, buffer, ' '))
		{
			do_op(buffer);
		}
	}
	std::cout << this->_stack.top() << std::endl;
}
